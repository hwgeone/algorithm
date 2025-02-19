#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

//有向无环图（DAG）
//它是一个 DAG 图，那么如何写出它的拓扑排序呢？这里说一种比较常用的方法：

//从 DAG 图中选择一个 没有前驱（即入度为0）的顶点并输出。
//从图中删除该顶点和所有以它为起点的有向边。
//重复 1 和 2 直到当前的 DAG 图为空或当前图中不存在无前驱的顶点为止。后一种情况说明有向图中必然存在环。

bool canFinishBFS(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int** edges = (int**)malloc(sizeof(int*) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        edges[i] = (int*)malloc(0);
    }
    int* edgeColSize = (int*)malloc(sizeof(int)* numCourses);
    memset(edgeColSize, 0, sizeof(int) * numCourses);
    int* indeg = (int*)malloc(sizeof(int) * numCourses);
    memset(indeg, 0, sizeof(int) * numCourses);

    //设置临接表
    for (int i = 0; i < prerequisitesSize; ++i) {
        //prerequisites[i] = [ai,bi] ，表示如果要学习课程ai,则必须先学习课程bi,
        //那就表明bi是边的开始，ai是边的结束
        int startOfEdge = prerequisites[i][1], endOfEdge = prerequisites[i][0];
        edgeColSize[startOfEdge]++;//出度加1
        edges[startOfEdge] = (int*)realloc(edges[startOfEdge], sizeof(int) * edgeColSize[startOfEdge]);
        edges[startOfEdge][edgeColSize[startOfEdge] - 1] = endOfEdge;
        ++indeg[endOfEdge]; //入度加1
    }

    //存放入度为0的节点的队列
    int* q = (int*)malloc(sizeof(int) * numCourses);
    //l 队列的后面 r 队列的前面
    int l = 0, r = -1;
    for (int i = 0; i < numCourses; ++i) {
        if (indeg[i] == 0) {
            //入队
            q[++r] = i;
        }
    }

    int visited = 0;
    while (l <= r) {
        ++visited;
        //出队
        int u = q[l++];
        for (int i = 0; i < edgeColSize[u]; ++i) {
            //临近点的入度减1
            --indeg[edges[u][i]];
            //临近点的入度为0
            if (indeg[edges[u][i]] == 0) {
                //临近点入队列
                q[++r] = edges[u][i];
            }
        }
    }
    for (int i = 0; i < numCourses; i++) {
        free(edges[i]);
    }
    free(edges);
    free(edgeColSize);
    free(indeg);
    free(q);
    return visited == numCourses;
}

int** edges;
int* edgeColSize;
int* visited;
bool valid;

void dfs(int u) {
    //u这个点搜索中
    visited[u] = 1;
    //遍历以u点为起始点的边
    for (int i = 0; i < edgeColSize[u]; ++i) {
        //此临近点没搜索过
        if (visited[edges[u][i]] == 0) {
            //继续深度搜索此临近点
            dfs(edges[u][i]);
            //临近点搜索中发现有环，直接返回（回溯的结束条件触发）
            if (!valid) {
                return;
            }
        }
        //u节点搜索中，发现有环，直接返回（回溯的结束条件触发）
        else if (visited[edges[u][i]] == 1) {
            valid = false;
            return;
        }
    }
    //u的所有临近点完成搜索，u标记为已完成搜索
    visited[u] = 2;
}

bool canFinishDFS(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    valid = true;
    edges = (int**)malloc(sizeof(int*) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        edges[i] = (int*)malloc(0);
    }
    edgeColSize = (int*)malloc(sizeof(int) * numCourses);
    memset(edgeColSize, 0, sizeof(int) * numCourses);
    visited = (int*)malloc(sizeof(int) * numCourses);
    memset(visited, 0, sizeof(int) * numCourses);
    for (int i = 0; i < prerequisitesSize; ++i) {
        //prerequisites[i] = [ai,bi] ，表示如果要学习课程ai,则必须先学习课程bi,
        //那就表明bi是边的开始，ai是边的结束
        int startOfEdge = prerequisites[i][1], endOfEdge = prerequisites[i][0];
        edgeColSize[startOfEdge]++;
        edges[startOfEdge] = (int*)realloc(edges[startOfEdge], sizeof(int) * edgeColSize[startOfEdge]);
        edges[startOfEdge][edgeColSize[startOfEdge] - 1] = endOfEdge;
    }
    for (int i = 0; i < numCourses && valid; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i < numCourses; i++) {
        free(edges[i]);
    }
    free(edges);
    free(edgeColSize);
    free(visited);
    return valid;
}



