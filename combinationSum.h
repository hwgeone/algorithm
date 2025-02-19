#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void findSums(int* c, int n, int cidx, int target, int** returnColumnSizes, int** res, int* residx, int* buffer, int bidx) {
    if (target == 0)
    {
        int* temp = (int*)calloc(bidx, sizeof(int));
        memcpy(temp, buffer, bidx * sizeof(int));

        res[*residx] = temp;
        (*returnColumnSizes)[*residx] = bidx;

        (*residx)++;
        return;
    }

    if (target < 0)
        return;

    for (int i = cidx; i < n; i++)
    {
        buffer[bidx] = c[i];
        findSums(c, n, i, target - c[i], returnColumnSizes, res, residx, buffer, bidx+1);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)calloc(80, sizeof(int*));
    *returnColumnSizes = (int*)calloc(1000, sizeof(int));
    int* buffer = (int*)calloc(1000, sizeof(int));
    *returnSize = 0;
    findSums(candidates,candidatesSize,0,target,returnColumnSizes,res,returnSize,buffer,0);
    *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * *returnSize);
    return res;
}
