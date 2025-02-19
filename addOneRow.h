#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth) {
	// Edge case: if the tree is empty
	if (depth == 1) {
		struct TreeNode* newRoot = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		newRoot->val = val;
		newRoot->left = root;
		newRoot->right = NULL;
		return newRoot;
	}

	struct TreeNode** queue = (struct TreeNode**)malloc(10000 * sizeof(struct TreeNode*));

	int front = 0, rear = 0, levelCount;

	//进队列rear++ 出队列front++ 
	//BST算法：队列+while 先左再右
	queue[rear++] = root;
	int currentLevel = 1;
	//循环树的每一层
	while (front < rear)
	{
		levelCount = rear - front;

		//遍历当前层
		for (int i = 0; i < levelCount; i++)
		{
			//当前在队列遍历的元素
			struct TreeNode* currentNode = queue[front++];

			if (currentLevel == depth - 1)
			{
				struct TreeNode* new1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
				struct TreeNode* new2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));

				struct TreeNode* left = currentNode->left;
				struct TreeNode* right = currentNode->right;

				new1->left = left;
				new1->right = NULL;
				new1->val = val;

				new2->right = right;
				new2->left = NULL;
				new2->val = val;

				currentNode->left = new1;
				currentNode->right = new2;
			}
			else
			{
				//把当前遍历的元素的左右节点加入到队里中
				if (currentNode->left)
					queue[rear++] = currentNode->left;
				if (currentNode->right)
					queue[rear++] = currentNode->right;
			}
		}

		if (currentLevel == depth - 1)
		{
			free(queue);
			return root;
		}
		currentLevel++;
	}

	free(queue);
	return root;
}