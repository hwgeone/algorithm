#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void findSums2(int* c, int n, int cidx, int target, int** returnColumnSizes, int** res, int* residx, int* buffer, int bidx, int* handledCandidates, int handIndex) {
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
int cmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int* handledCandidates = (int*)calloc(candidatesSize, sizeof(int));
    int** res = (int**)calloc(80, sizeof(int*));
    *returnColumnSizes = (int*)calloc(1000, sizeof(int));
    int* buffer = (int*)calloc(1000, sizeof(int));
    *returnSize = 0;
    findSums2(candidates, candidatesSize, 0, target, returnColumnSizes, res, returnSize, buffer, 0, handledCandidates, 0);
    *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * *returnSize);
    return res;
}