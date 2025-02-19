#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
//1 2 3 7 8 10
int arrayPairSum(int* nums, int numsSize) {
	qsort(nums, numsSize,sizeof(int), cmp);

	int sum = 0;
	for (int i = 0; i < numsSize; i += 2)
	{
		sum += nums[i];
	}

	return sum;
}