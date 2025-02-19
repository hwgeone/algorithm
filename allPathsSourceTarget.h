#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

void dfs(int** graph, int graphSize, int* graphColSize, int index, int** res,int* returnSize, int pathIndex,int* path,int* returnColumnSizes)
{
	if (index == graphSize - 1)
	{
		int pathCount = pathIndex;
		res[*returnSize] = (int*)malloc(sizeof(int) * pathCount);
		memcpy(res[(*returnSize)],path, sizeof(int) * pathCount);
		returnColumnSizes[(*returnSize)++] = pathCount;
		return;
	}
	
	//尝试走所有的邻近节点
	for (int i = 0; i < graphColSize[index]; i++)
	{
		int nextIndex = graph[index][i];
		path[pathIndex] = nextIndex;
		dfs(graph, graphSize, graphColSize,nextIndex,res, returnSize, pathIndex + 1,path, returnColumnSizes);
	}
}

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, 
	int* returnSize, int** returnColumnSizes) 
{
	int n = graphSize;

	int** res = (int**)malloc(sizeof(int*) * 10000);
	*returnColumnSizes = (int*)malloc(sizeof(int) * 10000);
	*returnSize = 0;
	int* path = (int*)malloc(sizeof(int) * 15);
	path[0] = 0;
	dfs(graph,graphSize, graphColSize,0,res,returnSize,1,path,*returnColumnSizes);

	return res;
}
