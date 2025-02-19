#include"uthash.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
	int x;
	int y;
} State;

State* GetNextStates(int curX, int curY, int x, int y, int* stateSize)
{
	State* states = (State*)malloc(sizeof(State) * 8);
	*stateSize = 0;
	// 以下两个状态，对应操作 1
	// 外部加水，使得 A 满
	if (curX < x) {
		State nextState1;
		nextState1.x = x;
		nextState1.y = curY;
		states[*stateSize] = nextState1;
		(*stateSize)++;
	}
	// 外部加水，使得 B 满
	if (curY < y) {
		State nextState2;
		nextState2.x = curX;
		nextState2.y = y;
		states[*stateSize] = nextState2;
		(*stateSize)++;
	}

	// 以下两个状态，对应操作 2
	// 把 A 清空
	if (curX > 0)
	{
		State nextState3;
		nextState3.x = 0;
		nextState3.y = curY;
		states[*stateSize] = nextState3;
		(*stateSize)++;
	}
	// 把 B 清空
	if (curY > 0)
	{
		State nextState4;
		nextState4.x = curX;
		nextState4.y = 0;
		states[*stateSize] = nextState4;
		(*stateSize)++;
	}

	// 以下四个状态，对应操作 3
	// 从 A 到 B，使得 B 满，A 还有剩
	if (curX - (y - curY) > 0)
	{
		State nextState5;
		nextState5.x = curX - (y - curY);
		nextState5.y = y;
		states[*stateSize] = nextState5;
		(*stateSize)++;
	}
	// 从 A 到 B，此时 A 的水太少，A 倒尽，B 没有满
	if (curX + curY < y)
	{
		State nextState6;
		nextState6.x = 0;
		nextState6.y = curX + curY;
		states[*stateSize] = nextState6;
		(*stateSize)++;
	}


	// 从 B 到 A，使得 A 满，B 还有剩余
	if (curY - (x - curX) > 0)
	{
		State nextState7;
		nextState7.x = x;
		nextState7.y = curY - (x - curX);
		states[*stateSize] = nextState7;
		(*stateSize)++;
	}
	// 从 B 到 A，此时 B 的水太少，B 倒尽，A 没有满
	if (curX + curY < x)
	{
		State nextState8;
		nextState8.x = curX + curY;
		nextState8.y = 0;
		states[*stateSize] = nextState8;
		(*stateSize)++;
	}
	states = (State*)realloc(states, sizeof(State) * (*stateSize));
	return states;
}

bool canMeasureWater(int x, int y, int z) {

	if (z == 0)
		return true;
	if (x + y < z)
		return false;

	State initState;
	initState.x = 0;
	initState.y = 0;
	struct hash {
		State key;
		// makes this structure hashable.
		UT_hash_handle hh;
	};
	// 广度优先遍历使用队列
	State* queue = (State*)malloc(sizeof(State) * 1000000);
	int left = 0, right = 0;
	queue[right++] = initState;
	struct hash* hashTable = NULL;
	struct hash* first = (struct hash*)malloc(sizeof(struct hash));
	HASH_ADD(hh, hashTable, key, sizeof(struct hash*), first);
	int count = 0;
	while (left < right) {
		State head = queue[left++];

		int curX = head.x;
		int curY = head.y;

		// curX + curY == z 比较容易忽略
		if (curX == z || curY == z || curX + curY == z) {
			return true;
		}

		// 从当前状态获得所有可能的下一步的状态
		int statesSize = 0;
		State* nextStates = GetNextStates(curX, curY, x, y, &statesSize);

		for (int i = 0; i < statesSize; i++) {
			count++;
			struct hash* h = NULL;
			HASH_FIND(hh, hashTable, &(nextStates[i]), sizeof(struct hash*), h);
			if (h == NULL) {
				queue[right++] = nextStates[i];
				//添加到队列以后，必须马上设置为已经访问，否则会出现死循环
				h = (struct hash*)malloc(sizeof(struct hash));
				h->key = nextStates[i];
				HASH_ADD(hh, hashTable, key, sizeof(struct hash*), h);
			}
		}

		free(nextStates);
	}

	free(queue);
	//free hash table
	struct hash* cur_usr = NULL;
	struct hash* next_usr = NULL;

	HASH_ITER(hh, hashTable, cur_usr, next_usr) {
		free(cur_usr);
	}
	return false;
}