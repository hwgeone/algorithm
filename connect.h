#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

 struct Node {
	int val;
	struct Node* left;
	struct Node* right;
	struct Node* next;
};

 struct Node* connect(struct Node* root) {
	 if (root == NULL)
		 return NULL;

	 //广度遍历
	 struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 20000);
	 int front = 0, rear = 0;
	 if (root)
	 {
		 queue[front++] = root;
	 }

	 while (front - rear > 0)
	 {
		 int queLen = front - rear;

		 for (int i = 0; i < queLen; i++)
		 {
			 struct Node* cur = queue[rear++];
			 if (i == queLen - 1)
				 cur->next = NULL;
			 else
				 cur->next = queue[rear];

			 if (cur->left)
				 queue[front++] = cur->left;
			 if (cur->right)
				 queue[front++] = cur->right;
		 }
	 }

	 free(queue);
	 return root;
 }