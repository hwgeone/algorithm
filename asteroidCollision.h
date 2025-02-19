#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* st = (int*)malloc(sizeof(int) * asteroidsSize);
    int pos = 0;
    for (int i = 0; i < asteroidsSize; i++) {
        bool alive = true;
        //栈还有元素，并且栈顶元素会撞向当前元素，并且当前元素没爆炸
        while (alive && asteroids[i] < 0 && pos > 0 && st[pos - 1] > 0) {
            alive = st[pos - 1] < abs(asteroids[i]); // 当前行星是否未爆炸
            if (st[pos - 1] <= abs(asteroids[i])) {  // 栈顶行星爆炸
                pos--;
            }
        }
        if (alive) {
            st[pos++] = asteroids[i];
        }
    }
    *returnSize = pos;
    return st;
}
