#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

bool trackback(int* nums, int numsSize,int k, int target, int* tmpArr, int index)
{
	if (index == numsSize)
	{
		for (int i = 0; i < k; i++)
		{
			if (tmpArr[i] != target)
				return false;
		}

		return true;
	}

	for (int i = 0; i < k; i++)
	{
		if (tmpArr[i] + nums[index] > target)
			continue;

		tmpArr[i] += nums[index];
		bool res = trackback(nums,numsSize,k,target, tmpArr,index+1);
		if (res)
			return true;
		tmpArr[i] -= nums[index];

		//如果第一个球，在第一个桶里面装不了，那么因为所有桶都是一样的，
		//其他桶肯定也装不了，提前结束
		if (tmpArr[i] == 0) {//再剪枝
			break;
		}
	}

	return false;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k) {
	int sum = 0;
	for (int i = 0; i < numsSize; i++)
	{
		sum += nums[i];
	}
	if (sum % k != 0)
		return false;

	int target = sum / k;
	int tmpArr[k];
	memset(tmpArr, 0, sizeof(int) * k);

	return trackback(nums,numsSize,k,target, tmpArr,0);
}