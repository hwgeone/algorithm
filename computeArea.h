#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

//第一个矩形由其左下顶点 (ax1, ay1) 和右上顶点 (ax2, ay2) 定义。
//第二个矩形由其左下顶点(bx1, by1) 和右上顶点(bx2, by2) 定义。
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int area1 = (ax2 - ax1) * (ay2 - ay1), area2 = (bx2 - bx1) * (by2 - by1);
    int overlapWidth = fmin(ax2, bx2) - fmax(ax1, bx1), overlapHeight = fmin(ay2, by2) - fmax(ay1, by1);
    int overlapArea = fmax(overlapWidth, 0) * fmax(overlapHeight, 0);
    return area1 + area2 - overlapArea;
}
