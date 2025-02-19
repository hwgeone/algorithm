#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

bool checkPerfectNumber(int num) {
	bool isP = false;
	int mid = num / 2;
	int sum = 0;
	while (mid > 0)
	{
		if (num % mid == 0)
			sum += mid;

		mid--;
	}

	return sum == num;
}