#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

//2,0,5,6,8,1,4,3,7
int arrayNesting(int* nums, int numsSize) {
    int ans = 0;
    bool* vis = (bool*)malloc(sizeof(bool) * numsSize);
    memset(vis, 0, sizeof(bool) * numsSize);
    for (int i = 0; i < numsSize; ++i) {
        int cnt = 0;
        int index = i;
        while (!vis[index]) {
            vis[index] = true;
            index = nums[index];
            ++cnt;
        }
        ans = MAX(ans, cnt);
    }
    free(vis);
    return ans;
}
