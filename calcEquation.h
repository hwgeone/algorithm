#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 // 题目分析：
 //equations中的各个参数是图节点
 //values为边权
 //对queries进行dfs检查是否存在路径，并收集边权乘机
 //图是有向图


#define MAX 10000
double res;
int* vis;
void dfs(char* start, char* target, double weight, char*** equations, int eRow, double* values) {
    //printf("Node = %s, weight = %0.2lf\n", start, weight);
    if (!strcmp(start, target)) { //strcmp返回0表示字符串相等
        res = weight; //收集满足题意的权值
        return;
    }
    //遍历equations寻找start点
    for (int i = 0; i < eRow; ++i) {
        //字符串相等且该边未访问
        if (!vis[i] && !strcmp(start, equations[i][0])) {
            vis[i] = 1;
            weight *= values[i];
            dfs(equations[i][1], target, weight, equations, eRow, values);
            weight /= values[i];
            vis[i] = 0;
        }
        else if (!vis[i] && !strcmp(start, equations[i][1])) {
            vis[i] = 1;
            weight /= values[i];
            dfs(equations[i][0], target, weight, equations, eRow, values);
            weight *= values[i];
            vis[i] = 0;
        }
        else continue;
    }
}

//判断str在不在集合中
bool inList(char** str, char*** equations, int eRow) {
    bool first = false, second = false;
    for (int i = 0; i < eRow; ++i) {
        //比较边左节点
        if (!first && (!strcmp(str[0], equations[i][0]) || !strcmp(str[0], equations[i][1]))) {
            first = true;
        }
        //比较边的右节点
        if (!second && (!strcmp(str[1], equations[i][0]) || !strcmp(str[1], equations[i][1]))) {
            second = true;
        }
    }
    return first && second; //两个元素都找到了才返回true;
}
//输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], 
//queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
//输出：[6.00000, 0.50000, -1.00000, 1.00000, -1.00000]
double* calcEquation(char*** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char*** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    vis = (int*)malloc(sizeof(int) * equationsSize);
    //ans收集答案
    double* ans = (double*)malloc(sizeof(double) * MAX);
    int ansTop = 0;
    //遍历问题集，检查是否存在路径
    for (int i = 0; i < queriesSize; ++i) {
        //如果该元素不在集合中，则跳过
        if (!inList(queries[i], equations, equationsSize)) {
            ans[ansTop++] = -1.0;
            continue;
        }
        //元素在集合中则寻找路径
        res = -1.0;
        //清空边访问记录
        memset(vis, 0, sizeof(int) * equationsSize);
        dfs(queries[i][0], queries[i][1], 1.0, equations, equationsSize, values);
        ans[ansTop++] = res;
    }
    *returnSize = ansTop;
    return ans;
}
