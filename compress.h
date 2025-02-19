#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

//输入：chars = ["a","a","b","b","c","c","c"]
//输出：返回 6 ，输入数组的前 6 个字符应该是：["a", "2", "b", "2", "c", "3"]
void swap(char* a, char* b) {
    char t = *a;
    *a = *b, * b = t;
}

void reverse(char* a, char* b) {
    while (a < b) {
        swap(a++, --b);
    }
}

int compress(char* chars, int charsSize) {
    int write = 0, left = 0;
    for (int read = 0; read < charsSize; read++) {
        //当前读的位置是最后一个字符或者当前读的位置和下一个位置的字符不相等
        if (read == charsSize - 1 || chars[read] != chars[read + 1]) {
            //写入字符（重不重复，都要写入）
            chars[write++] = chars[read];
            //子串的长度
            int num = read - left + 1;
            //处理重复长度大于1的子串的数字部分的写入
            if (num > 1) {
                //标记子串开始写的位置
                int anchor = write;
                while (num > 0) {
                    //将数字倒着写入
                    chars[write++] = num % 10 + '0';
                    num /= 10;
                }
                //根据开始和结束写入的位置，原地翻转字符串
                reverse(&chars[anchor], &chars[write]);
            }
            //子串处理结束，重新记录left的位置
            left = read + 1;
        }
    }
    return write;
}
