#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	if (preorderSize <= 0 || inorderSize <= 0) {
		return NULL;
	}
	struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	p->val = *preorder;
	p->left = NULL;
	p->right = NULL;
	int pos = 0;
	for (pos = 0; pos < inorderSize; pos++) {
		if (inorder[pos] == *preorder)
			break;
	}
	//preorder = [3, 9, 20, 15, 7]
	//inorder =  [9, 3, 15, 20, 7]

	// left
	p->left = buildTree(preorder + 1, pos + 1 - 1, inorder, pos);
	// right
	p->right = buildTree(preorder + pos + 1, preorderSize - pos - 1, inorder + pos + 1, preorderSize - pos - 1);
	return p;
}

struct TreeNode* buildTree2(int* inorder, int inorderSize, int* postorder, int postorderSize) {
	if (postorderSize <= 0 || inorderSize <= 0) {
		return NULL;
	}
	struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	p->val = postorder[postorderSize - 1];
	p->left = NULL;
	p->right = NULL;
	int pos = 0;
	for (pos = 0; pos < inorderSize; pos++) {
		if (inorder[pos] == postorder[postorderSize - 1])
			break;
	}
	//中序：CDBAE
	//后序：DCBEA
	//根据postorder的最后一个元素确定当前递归的根元素
	//从inorder中找到该元素的位置
	//该位置作为下次递归的参数

	//对于左子树 
	p->left = buildTree(inorder, pos, postorder, pos);
	p->right = buildTree(inorder + pos + 1, inorderSize - pos, postorder + pos, postorderSize - pos - 1);

	return p;
}

struct TreeNode* dfs(int* inorder, int i_left, int i_right, int* postorder, int p_left, int p_right)
{
	if (i_left > i_right)//数组为0
	{
		return NULL;
	}
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));//构造节点，并初始化
	root->val = postorder[p_right];
	root->left = NULL;
	root->right = NULL;
	for (int i = i_left; i <= i_right; i++)//切割中序数组
	{
		if (inorder[i] == postorder[p_right])//找到了切割点
		{
			//就是中序数组大小一定是和后序数组的大小相同的
			root->left = dfs(inorder, i_left, i - 1, postorder, p_left, p_left + i - 1 - i_left);
			root->right = dfs(inorder, i + 1, i_right, postorder, p_left + i - i_left, p_right - 1);
		}
	}
	return root;
}

struct TreeNode* buildTree3(int* inorder, int inorderSize, int* postorder, int postorderSize) {
	return dfs(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);//递归构造
}

