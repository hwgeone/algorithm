﻿#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

bool checkValidString(char* s) {
    int n = strlen(s);
    bool** dp = (bool**)malloc(sizeof(bool*) * n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = (bool*)malloc(sizeof(bool) * n);
    }

    //一个字符的情况
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            dp[i][i] = true;
        }
    }
    //两个字符的情况
    for (int i = 1; i < n; i++) {
        char c1 = s[i - 1], c2 = s[i];
        dp[i - 1][i] = (c1 == '(' || c1 == '*') && (c2 == ')' || c2 == '*');
    }

    //三个包括三个字符以上的情况
    //s[i,j]
    for (int i = n - 3; i >= 0; i--) {
        char c1 = s[i];
        for (int j = i + 2; j < n; j++) {
            char c2 = s[j];
            if ((c1 == '(' || c1 == '*') && (c2 == ')' || c2 == '*')) {
                dp[i][j] = dp[i + 1][j - 1];
            }
            for (int k = i; k < j && !dp[i][j]; k++) {
                dp[i][j] = dp[i][k] && dp[k + 1][j];
            }
        }
    }
    return dp[0][n - 1];
}
