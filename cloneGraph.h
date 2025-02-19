#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

struct Node {
	int val;
	int numNeighbors;
	struct Node** neighbors;
};

struct Node** visited;

struct Node* dfs(struct Node* s) {
	if (s == NULL)
		return NULL;

	if (visited[s->val])
		return visited[s->val];

	struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
	copy->val = s->val;
	copy->numNeighbors = s->numNeighbors;
	copy->neighbors = (struct Node**)malloc(sizeof(struct Node*)* copy->numNeighbors);
	visited[s->val] = copy;

	for (int i = 0; i < copy->numNeighbors; i++)
	{
		copy->neighbors[i] = dfs(s->neighbors[i]);
	}

	return copy;
}

struct Node* cloneGraph(struct Node* s) {
	visited = (struct Node**)malloc(sizeof(struct Node*) * 101);
	memset(visited, 0, 101*sizeof(struct Node*));
	return dfs(s);
}