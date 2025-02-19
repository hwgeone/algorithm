#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

double champagneTower(int poured, int query_row, int query_glass) {
    double f[1000][1000] = {0.0};
    int k = poured;
    int n = query_row;
    int m = query_glass;
    //m<=n
    //dp[i][j]的含义：到了k杯后的第i行第j列的杯子经流的水量
    //倒满一杯，经流的水量+1
    f[0][0] = 1*k;
    //从最上面的杯子开始计算
    for (int i = 0; i <= n; i++) {
        //每行杯子从左到右计算
        for (int j = 0; j <= i; j++) {
            //第i行第j列的杯子没有溢出，表示前面已经推导出结果，直接跳过
            if (f[i][j] <= 1) continue;
            //当前的杯子溢出了
            //下行的左右两个杯子的推导公式=》当前杯子溢出份额等分
            f[i + 1][j] += (f[i][j] - 1) / 2;
            f[i + 1][j + 1] += (f[i][j] - 1) / 2;
        }
    }
    return fmin(f[n][m], 1);
}
