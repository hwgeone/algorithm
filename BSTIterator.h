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

typedef struct {
	int* store;
	int count;
	int index;
} BSTIterator;

int GetTreeNodeCount(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + GetTreeNodeCount(root->left) + GetTreeNodeCount(root->right);
}

void loop(struct TreeNode* root,int* store,int* index)
{
	if (root == NULL)
		return;
	loop(root->left, store, index);
	store[(*index)++] = root->val;
	loop(root->right, store, index);
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
	BSTIterator* res = (BSTIterator*)malloc(sizeof(BSTIterator));
	int count = GetTreeNodeCount(root);
	res->count = count;
	res->index = 0;
	res->store = (int*)malloc(sizeof(int) * count);

	int index = 0;
	loop(root,res->store,&index);
	return res;
}

int bSTIteratorNext(BSTIterator* obj) {
	return obj->store[obj->index++];
}

bool bSTIteratorHasNext(BSTIterator* obj) {
	if (obj->index > obj->count - 1)
	{
		return false;
	}
	return true;
}

void bSTIteratorFree(BSTIterator* obj) {
	free(obj->store);
	free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);

 * bool param_2 = bSTIteratorHasNext(obj);

 * bSTIteratorFree(obj);
*/