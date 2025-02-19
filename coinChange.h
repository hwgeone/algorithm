#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>
//3 7
int coinChange(int* coins, int coinsSize, int amount) {
	int* dp = (int*)malloc(sizeof(int) * (amount + 1));
	for (int i = 1; i <= amount; i++)
	{
		dp[i] = amount + 1;
	}

	dp[0] = 0;

	for (int i = 1; i <= amount; i++)
	{
		for (int j = 0; j < coinsSize; j++)
		{
			if (i - coins[j] >= 0)
			{
				dp[i] = fmin(dp[i],dp[i-coins[j]] + 1);
			}
		}
	}

	return dp[amount] > amount?-1:dp[amount];
}
