#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

//输入：amount = 5, coins = [1, 2, 5]
//输出：4
//5 = 5
//5 = 2 + 2 + 1
//5 = 2 + 1 + 1 + 1
//5 = 1 + 1 + 1 + 1 + 1
//int change(int amount, int* coins, int coinsSize) {
//    int dp[amount + 1];
//    memset(dp, 0, sizeof(dp));
//    dp[0] = 1;
//    for (int i = 0; i < coinsSize; i++) {
//        //
//        for (int j = coins[i]; j <= amount; j++) {
//            //分两种情况：
//            //用当前金币coins[i]，能够达到当前金额j：说明dp[j]等于dp[j - coins[i]]
//            //不用当前金币coins[i]，能够达到当前金额j：说明dp[j]等于前一次币种累计算得的dp[j]
//            //两种情况累加，得dp[j] =dp[j] + dp[j - coins[i]]
//            dp[j] += dp[j - coins[i]];
//        }
//    }
//    return dp[amount];
//}

int change(int amount, int* coins, int coinsSize) {
    //dp含义：
    //用前i个币种能达到金额j的方案数
    //
    int** dp = (int**)malloc(sizeof(int*) * (coinsSize + 1));
    for (int i = 0; i <= coinsSize;i++)
    {
        dp[i] = (int*)malloc(sizeof(int) * (amount + 1));
        memset(dp[i], 0, sizeof(int) * (amount + 1));
    }

    //不用任何币种，达到金额0的方案数是1
    dp[0][0] = 1;
    for (int i = 1; i <= coinsSize; i++) {
        //分两种情况：
        //用当前金币coins[i]，能够达到当前金额j：说明dp[i][j]等于dp[i][j - coins[i]]
        //不用当前金币coins[i]，能够达到当前金额j：说明dp[i][j]等于前一次币种累计算得的dp,即dp[i-1][j]
        //两种情况累加，得dp[i][j] = dp[i-1][j] + dp[i][j - coins[i]]
        for (int j = 0; j <= amount; j++) {
            //没选coins[i]
            dp[i][j] = dp[i - 1][j];
            //选了coins[i]
            for (int k = 1; k * coins[i - 1] <= j; k++) {
                dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
            }
        }
    }
    return dp[coinsSize][amount];
}
