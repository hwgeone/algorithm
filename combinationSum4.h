#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

//输入：nums = [1, 2, 3], target = 4
//输出：7
//解释：
//所有可能的组合为：
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//请注意，顺序不同的序列被视作不同的组合。

int combinationSum4(int* nums, int numsSize, int target) {
	long* dp = (long*)calloc(target + 1,sizeof(long));
	dp[0] = 1;

	for (int i = 1; i <= target; i++)
	{
		for (int j = 0; j < numsSize; j++)
		{
			if (i >= nums[j] && dp[i - nums[j]] < INT_MAX - dp[i])
			{
				dp[i] += dp[i - nums[j]];
			}
		}
	}

	return dp[target];
}