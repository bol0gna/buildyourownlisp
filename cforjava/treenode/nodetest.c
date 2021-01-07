/*
 * Simple program to test functionality of TreeNode from treenode.c/treenode.h
 */

#include <stdio.h>
#include "treenode.h"

int main(int argc, char* argv[]) {
	TreeNode a = new_TreeNode(123);
	TreeNode b = new_TreeNode(7);
	TreeNode c = new_TreeNode(1);

	TreeNode_print(a);
	TreeNode_print(b);
	TreeNode_print(c);
	printf("\n");
}
