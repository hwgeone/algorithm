#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

// n >= 1
//5
//4
//2
int arrangeCoins(int n) {
	int stairLevel = 1;
	while (n >= stairLevel)
	{
		n -= stairLevel;
		stairLevel++;
	}

	return stairLevel - 1;
}

//有三种解法
//方法一，暴力法，时间复杂度为O(N)，直接while循环，剩余值大于等于下一行行号
 int arrangeCoins1(int n) {
    if (n < 1) {
        return 0;
    }
    int rowNum = 1;
    int remain = n - rowNum;
    while (remain >= rowNum + 1) {//rowNum行有rowNum个硬币，所以remain值必须大于等于下一行rowNum+1
        rowNum++;//统计有效的rowNum
        remain = remain - rowNum;//更新剩余的值
    }
    return rowNum;
}

//方法二，二分查找法，时间复杂度O(LogN).思路就是找到一个k，使得所有和刚好大于n，那么k-1就是答案。这个假设是基于行号k=n。
 int arrangeCoins(int n) {
     if (n < 0) {
         return -1;
     }
     if (n <= 1) {
         return n;
     }
     if (n <= 3) {
         return n == 3 ? 2 : 1;
     }

     // Binary Search space will start from 2 to n/2.
     long start = 2;
     long end = n / 2;
     while (start <= end) {
         long mid = start + (end - start) / 2;
         long coinsFilled = mid * (mid + 1) / 2;
         if (coinsFilled == n) {
             return (int)mid;
         }
         if (coinsFilled < n) {
             start = mid + 1;
         }
         else {
             end = mid - 1;
         }
     }

     // Since at this point start > end, start will start pointing to a value greater
     // than the desired result. We will return end as it will point to the correct
     // int value.
     return (int)end;
 }
//方法三，就是数学方法
//时间复杂度O(1)，利用了等差数列的性质，等式n = (1 + x) * x / 2,
//一元二次方程的求根公式 x = (-1 + sqrt(8 * n + 1)) / 2

 int arrangeCoins3(int n)
 {
     int res = (sqrt(8 * (double)n + 1) - 1) / 2;
     return res;

 }