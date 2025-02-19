#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "uthash.h"

typedef struct HashItem {
    int key;
    bool val;
    UT_hash_handle hh;
} HashItem;

bool dfs(int maxChoosableInteger, int usedNumbers, int desiredTotal, int currentTotal, HashItem** memo) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*memo, &usedNumbers, pEntry);
    //记忆化的hashMap,用来记录选择了哪些树的情况，当前玩家的胜负；用以减少时间复杂度
    //如果未曾玩过这种场景，则做下列工作找出这种场景的答案
    if (NULL == pEntry) {
        bool res = false;
        //循环遍历选择每个数的情况，如果循环完所有的情况，都赢不了，那么就输了，因此初始res是输
        for (int i = 0; i < maxChoosableInteger; i++) {
            //若这个数还没被选择，才往下做逻辑，否则进入下一轮循环(注意这里i是从0开始，所以判断的是第i+1个数的情况)
            if (((usedNumbers >> i) & 1) == 0) {
                //如果选完能直接胜利，那么结果自然为true
                if (i + 1 + currentTotal >= desiredTotal) {
                    res = true;
                    break;
                }
                //否则的话，递归判断，我选完后，对方选完是不是就输了；对方输了，我自然就赢了，有点绕
                if (!dfs(maxChoosableInteger, usedNumbers | (1 << i), desiredTotal, currentTotal + i + 1, memo)) {
                    res = true;
                    break;
                }
            }
        }
        //把结果放入记忆化
        pEntry = (HashItem*)malloc(sizeof(HashItem));
        pEntry->key = usedNumbers;
        pEntry->val = res;
        HASH_ADD_INT(*memo, key, pEntry);
    }
    return pEntry->val;
    //对于二进制不熟的同学，以下解释一下这题移位法两个操作：（userNumbers >> i) & 1 ：判断i+1是否已经被访问； userNumbers | (1 << i)：把i+1标记为访问。大家可以草稿纸看一下，很好理解
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    HashItem* memo = NULL;
    //所有1-maxChoosableInteger的数字加起来的和依旧小于desiredTotal
    if ((1 + maxChoosableInteger) * (maxChoosableInteger) / 2 < desiredTotal) {
        return false;
    }
    return dfs(maxChoosableInteger, 0, desiredTotal, 0, &memo);
}
