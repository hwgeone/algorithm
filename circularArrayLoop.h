#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

//1 2 3 4 5
int next(int* nums, int numsSize, int cur) {
    //A = (cur + nums[cur]) % numsSize 保证返回值小于n
    //(A + numsSize) % numsSize 保证返回值大于等于0
    return ((cur + nums[cur]) % numsSize + numsSize) % numsSize;  // 保证返回值在 [0,n) 中
}

bool circularArrayLoop(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (!nums[i]) {
            continue;
        }
        int slow = i, fast = next(nums, numsSize, i);
        // 判断非零且方向相同
        //三个位置 A，B，C
        //A是第一步的位置
        //B是第二步的位置
        //C是第三步的位置
        //nums[A] * nums[B] > 0 && nums[B] * nums[C] > 0
        //说明A B C 的前进方向相同
        while (nums[slow] * nums[fast] > 0 
            && nums[slow] * nums[next(nums, numsSize, fast)] > 0) {
            if (slow == fast) {
                //不是单个环（环内至少两个元素）
                if (slow != next(nums, numsSize, slow)) {
                    return true;
                }
                else {
                    break;
                }
            }
            slow = next(nums, numsSize, slow);
            fast = next(nums, numsSize, next(nums, numsSize, fast));
        }
        int add = i;
        //已经走过的点置0，因为上面过程说明没环，走过的路径上任意一点出发都不可能形成环
        //减少外层循环的次数
        while (nums[add] * nums[next(nums, numsSize, add)] > 0) {
            int tmp = add;
            add = next(nums, numsSize, add);
            nums[tmp] = 0;
        }
    }
    return false;
}

