#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sumAllDigits(int num)
{
	int sum = 0;
	while (num != 0)
	{
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

int addDigits(int num) {
	if (num < 10)
		return num;

	return addDigits(sumAllDigits(num));
}