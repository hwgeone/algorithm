#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

int operateStack(int* stack, char* s, int stackTop)
{
	char* p = s;
	while (*p)
	{
		if (*p == '#')
		{
			if (stackTop > 0)
			{
				(stackTop)--;
			}
		}
		else
		{
			stack[stackTop] = *p;
			(stackTop)++;
		}
		p++;
	}

	return stackTop;
}

bool backspaceCompare(char* s, char* t) {
	int* stackA = (int*)malloc(sizeof(int) * 1000);
	int* stackB = (int*)malloc(sizeof(int) * 1000);
	int stackATop = 0, stackBTop = 0;

	stackATop = operateStack(stackA, s, stackATop);
	stackBTop = operateStack(stackB, t, stackBTop);

	if (stackATop != stackBTop)
	{
		free(stackA);
		free(stackB);
		return false;
	}
	else 
	{
		for (int i = 0; i < stackATop; i++)
		{
			if (stackA[i] != stackB[i])
			{
				free(stackA);
				free(stackB);
				return false;
			}
		}
	}

	free(stackA);
	free(stackB);

	return true;
}
