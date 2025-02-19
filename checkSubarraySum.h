#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include"uthash.h"

struct HashTable {
    int key, val;
    UT_hash_handle hh;
};

//同余定理
bool checkSubarraySum(int* nums, int numsSize, int k) {
    int m = numsSize;
    if (m < 2) {
        return false;
    }
    struct HashTable* hashTable = NULL;
    struct HashTable* tmp = (struct HashTable*)malloc(sizeof(struct HashTable));
    tmp->key = 0, tmp->val = -1;
    HASH_ADD_INT(hashTable, key, tmp);
    //余数
    int remainder = 0;
    for (int i = 0; i < m; i++) {
        //有N个数nums
        //N个数和对K的余数 = 遍历nums，(nums[i] + 上次的余数)%k
        remainder = (remainder + nums[i]) % k;
        HASH_FIND_INT(hashTable, &remainder, tmp);
        if (tmp != NULL) {
            int prevIndex = tmp->val;
            if (i - prevIndex >= 2) {
                return true;
            }
        }
        else {
            tmp = (struct HashTable*)malloc(sizeof(struct HashTable));
            tmp->key = remainder, tmp->val = i;
            HASH_ADD_INT(hashTable, key, tmp);
        }
    }
    return false;
}
