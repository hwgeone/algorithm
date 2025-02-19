#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

//1-3
//5

bool canWinNimX(int n, int* turn)
{
	(*turn)++;
	if (n < 4)
	{
		if (*turn % 2 != 0)
			return true;
		else
			return false;
	}
		

	return canWinNimX(n - 1, turn) || canWinNimX(n - 2, turn) || canWinNimX(n - 3, turn);
}

bool canWinNim(int n) {
	return n % 4 != 0 ? true : false;//只要不是4的倍数就赢
}
