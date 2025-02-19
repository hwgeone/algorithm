#include<stdlib.h>
#include <stdio.h>
#include"Struct.h"

int GetMul(int a);

int GetMul(int a)
{
	int m = 1;
	while (a-- > 1)
	{
		m = m*10;
	}

	return m;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int first = 0;
	int last = 0;

	int index1 = 1, index2 = 1;
	while (l1)
	{
		int xxx = GetMul(index1);
		first += l1->val * xxx;
		index1++;
		l1 = l1->next;
	}

	while (l2)
	{
		last += l2->val * GetMul(index2);
		index2++;
		l2 = l2->next;
	}

	first = first + last;
	struct ListNode* newList = NULL;
	struct ListNode* loop = NULL;
	struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (!tmp)
	{
		exit(1);
	}
	tmp->val = first % 10;
	tmp->next = NULL;
	newList = tmp;
	loop = newList;
	last = first / 10;

	while (last > 0)
	{
		struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));

		if (!tmp)
			exit(1);
		tmp->val = last % 10;
		tmp->next = NULL;

		loop->next = tmp;
		loop = loop->next;

		last = last / 10;
	}

	return newList;
}

//4 5 6
struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2) {
	int stack1[100] = { 0 }, stack2[100] = { 0 };
	int i1 = -1, i2 = -1;
	while (l1)
	{
		stack1[++i1] = l1->val;
		l1 = l1->next;
	}
	while (l2)
	{
		stack2[++i2] = l2->val;
		l2 = l2->next;
	}
	int carry = 0;
	struct ListNode* res = NULL;
	
	while ((i1 >= 0 || i2 >= 0) || carry != 0)
	{
		int a = i1 >= 0 ? stack1[i1] : 0;
		int b = i2 >= 0 ? stack2[i2] : 0;
		int cur = a + b + carry;
		carry = cur / 10;
		cur %= 10;

		struct ListNode* curNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		curNode->val = cur;
		curNode->next = res;
		res = curNode;
		i1--; i2--;
	}

	return res;
}
