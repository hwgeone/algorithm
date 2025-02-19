#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

//1,2,3,6
bool canPartition(int* nums, int numsSize) {
    int len = numsSize;
    // 题目已经说非空数组，可以不做非空判断
    int sum = 0;
    for (int i = 0; i < numsSize;i++) {
        sum += nums[i];
    }
    // 特判：如果是奇数，就不符合要求
    if ((sum & 1) == 1) {
        return false;
    }

    int target = sum / 2;
    // 创建二维状态数组，行：物品索引，列：容量（包括 0）
    //状态定义：dp[i][j]表示从数组的 [0, i] 
    //这个子区间内挑选一些正整数，每个数只能用一次，使得这些数的和恰好等于 j。
    bool** dp = (bool**)malloc(sizeof(bool*) * len);
    for (int i = 0; i < len; i++)
    {
        dp[i] = (bool*)malloc(sizeof(bool) * (target + 1));
        memset(dp[i],0, sizeof(bool) * (target + 1));
    }
    // 先填表格第 0 行，第 1 个数只能让容积为它自己的背包恰好装满
    if (nums[0] <= target) {
        dp[0][nums[0]] = true;
    }
    // 再填表格后面几行
    for (int i = 1; i < len; i++) {
        for (int j = 0; j <= target; j++) {
            // 直接从上一行先把结果抄下来，然后再修正
            dp[i][j] = dp[i - 1][j];

            if (nums[i] == j) {
                dp[i][j] = true;
                continue;
            }
            if (nums[i] < j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
            }
        }
    }
    return dp[len - 1][target];
}
