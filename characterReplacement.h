#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

//s = "AABABBA", k = 1
int characterReplacement(char* s, int k)
{
    if (s == NULL) {
        return 0;
    }
    int map[26] = {0};

    int left = 0;
    int right = 0;
    int historyCharMax = 0;
    int slen = strlen(s);

    //窗口不断往右扩张
    for (right = 0; right < slen; right++) {
        int index = s[right] - 'A';
        map[index]++;
        historyCharMax = fmax(historyCharMax, map[index]);

        //窗口大小极限是historyCharMax + k
        //达到极限了，窗口平移

        //错误代码例子：AABABBA，k=1
        //if (right - left + 1 >= historyCharMax + k) {
        //    return historyCharMax + k;
        //}
        //这里我是反着想的，如果还有容错机会，左边界就不用右移，
        //直接下一层循环right++移动有边界扩大窗口
        if (right - left + 1 <= historyCharMax + k) {
           
        }
        else
        {
            map[s[left] - 'A']--;  //先把左边界元素记录个数-1，再右移
            left++;
        }
    }
    return right - left;
}
