﻿#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "uthash.h"

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

#define RET_LEN             1000
#define RET_COL_LEN         1000

char* ret_[RET_LEN][RET_COL_LEN];
char** ret[RET_LEN];
int ret_col[RET_LEN];

int find(int* fa, int x) {
    if (x == fa[x]) {
        return fa[x];
    }

    fa[x] = find(fa, fa[x]);
    return fa[x];
}

void join(int* fa, int x, int y) {
    int xx = find(fa, x);
    int yy = find(fa, y);

    if (xx == yy) {
        return;
    }

    if (xx < yy) {
        fa[yy] = xx;
    }
    else {
        fa[xx] = yy;
    }
}

typedef struct _hash_st {
    char* key;
    int val;
    UT_hash_handle hh;
}hash_st;

int compare(hash_st* a, hash_st* b) {
    return strcmp(a->key, b->key);
}

//【算法思路】HASH + 字符串 + 并查集 + 排序。
// 遍历一个账户中的邮箱，如果已经出现过，则进行合并；如果未出现过，则新建hash表项
// 遍历并查集，将结果整合
char*** accountsMerge(char*** accounts, int accountsSize, int* accountsColSize, int* returnSize, int** returnColumnSizes) {
    if (accountsSize <= 1) {
        *returnSize = accountsSize;
        *returnColumnSizes = accountsColSize;
        return accounts;
    }

    int* fa = (int*)calloc(accountsSize, sizeof(int));

    for (int i = 0; i < accountsSize; i++) {
        fa[i] = i;
    }

    //遍历accounts，按照邮箱建立hash表
    hash_st* head = NULL;

    for (int i = 0; i < accountsSize; i++) {
        for (int j = 1; j < accountsColSize[i]; j++) {
            char* key = accounts[i][j];

            hash_st* tmph;
            HASH_FIND(hh, head, key, strlen(key), tmph);

            if (tmph == NULL) {
                tmph = (hash_st*)calloc(1, sizeof(hash_st));
                tmph->key = key;
                tmph->val = i;

                HASH_ADD_KEYPTR(hh, head, tmph->key, strlen(tmph->key), tmph);
            }
            else {
                join(fa, i, tmph->val);
            }
        }
    }

    HASH_SORT(head, compare);

    //建立账户下标和结果下标的映射关系,结果下标 = map[账户下标] - 1
    int* map = (int*)calloc(accountsSize, sizeof(int));
    int rsize = 0;

    //遍历hash表，将所有结果分别放入不同的根结果中
    hash_st* hp0, * hp1;
    HASH_ITER(hh, head, hp0, hp1) {
        int fid = find(fa, hp0->val);

        //printf("(%d -> %d) %s\n", hp0->val, fid, hp0->key);

        if (map[fid] == 0) {
            map[fid] = rsize + 1;

            //首次有加入结果中
            ret[rsize] = ret_[rsize];
            ret_col[rsize] = 0;

            ret[rsize][ret_col[rsize]++] = accounts[fid][0];
            ret[rsize][ret_col[rsize]++] = hp0->key;
            rsize++;
        }
        else {
            int rid = map[fid] - 1;
            ret[rid][ret_col[rid]++] = hp0->key;
        }
    }

    *returnSize = rsize;
    *returnColumnSizes = ret_col;
    return ret;
}