/* 
 * Binary search tree implementation in C.
 * Activity/lesson 4 from "C for Java Programmers"
 */

#include <stdlib.h>
#include <stdio.h>
#include "treenode.h"

struct treenode {
	int info;
	TreeNode left;
	TreeNode right;
};

TreeNode new_TreeNode(int val) {
	TreeNode this = (TreeNode)malloc(sizeof(struct treenode));
	if (this == NULL) {
		return NULL; // out of memory
	}

	this->info = val;
	this->left = NULL;
	this->right = NULL;

	return this;
}

void free_TreeNode(TreeNode this) {
	if (this == NULL) return;
	if (this->left == NULL && this->right == NULL) {
		free(this);
		return;
	}
	free_TreeNode(this->left);
	free_TreeNode(this->right);
}

void TreeNode_print(TreeNode this) {
	if (this != NULL) {
		printf("Node[%d]", this->info);
	}
}

void TreeNode_printTree(TreeNode this) {
	if (this != NULL) {
		TreeNode_printTree(this->left);
		TreeNode_print(this);
		TreeNode_printTree(this->right);
	}
}
