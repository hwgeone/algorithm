#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

//[4,8,2,5,7,8]
bool checkPossibility(int* nums, int numsSize)
{
    if (numsSize <= 2)   return true;
    bool flag = nums[0] <= nums[1] ? true : false; // 标识是否还能修改

    // 遍历时，每次需要看连续的三个元素
    //A,B,C
    for (int i = 1; i < numsSize - 1; i++)
    {
        //C<B
        if (nums[i] > nums[i + 1])  // 出现递减
        {
            //进行到这儿，A<=B
            if (flag)   // 如果还有修改机会，进行修改
            {
                //A<=C<B
                //这种情况 B缩小到C，ABC依旧非递减，也不影响后续，因为C没变
                if (nums[i + 1] >= nums[i - 1])// 修改方案1
                    nums[i] = nums[i + 1];
                //A>C,C<B,A<=B 
                //这种情况，C比AB都小，只能把C变成B
                else                            // 修改方案2
                    nums[i + 1] = nums[i];
                flag = false;                   // 用掉唯一的修改机会
            }
            else        // 没有修改机会，直接结束
                return false;
        }
    }
    return true;
}

