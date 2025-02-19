#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

//[3,2,1,0,4]
bool canJumpWithDP(int* nums, int numsSize) {
	if (numsSize == 1)
		return true;
	bool* dp = (bool*)malloc(sizeof(bool) * numsSize);
	dp[0] = true;
	
	for (int i = 1; i < numsSize; i++)
	{
		dp[i] = false;
		for (int j = 0; j < i; j++)
		{
			printf("%d", nums[j]);
			if (j + nums[j] >= i && dp[j] == true)
			{
				dp[i] = true;
				break;
			}
		}
	}

	return dp[numsSize-1];
}

//贪心
bool canJump(int* nums, int numsSize) {
	if (numsSize == 1)
		return true;
	
	int canReachLen = nums[0];
	for (int i = 1; i < numsSize; i++)
	{
		if (i > canReachLen)
			return false;
		canReachLen = fmax(canReachLen, i + nums[i]);
	}

	return true;
}