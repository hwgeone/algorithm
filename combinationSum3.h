#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

int kC = 0;

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
        findSums(c, n, i, target - c[i], returnColumnSizes, res, residx, buffer, bidx + 1);
    }
}
void findSums2(int* c, int n, int cidx, int target, int** returnColumnSizes, int** res, int* residx, int* buffer, int bidx, int* handledCandidates, int handIndex) {
    if (target == 0)
    {
        if (bidx == kC)
        {
            int* temp = (int*)calloc(bidx, sizeof(int));
            memcpy(temp, buffer, bidx * sizeof(int));

            res[*residx] = temp;
            (*returnColumnSizes)[*residx] = bidx;

            (*residx)++;
        }
        return;
    }

    if (target < 0)
        return;

    //[3,1,3,5,1,1]
    //[1,1,1,3,3,5] 8
    //[[1,1,1,5],[1,1,3,3],[3,5],[3,5]]
    for (int i = cidx; i < n; i++)
    {
        buffer[bidx] = c[i];
        int tt = c[i];

        findSums2(c, n, i + 1, target - tt, returnColumnSizes, res, residx, buffer, bidx + 1, handledCandidates, handIndex);
        handledCandidates[handIndex] = c[i];
        int index = i + 1;
        while (index < n)
        {
            //过滤掉后面相同的元素
            if (handledCandidates[handIndex] == c[i + 1])
                i++;
            else
            {
                break;
            }
            index++;
        }
        handIndex++;
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    kC = k;
    int nums[9] = {1,2,3,4,5,6,7,8,9};
    int** res = (int**)calloc(80, sizeof(int*));
    int* handledCandidates = (int*)calloc(9, sizeof(int));
    *returnColumnSizes = (int*)calloc(1000, sizeof(int));
    int* buffer = (int*)calloc(1000, sizeof(int));
    *returnSize = 0;
    findSums2(nums, 9, 0, n, returnColumnSizes, res, returnSize, buffer, 0,handledCandidates,0);
    *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * *returnSize);
    return res;
}
