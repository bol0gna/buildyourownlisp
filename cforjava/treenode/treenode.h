/* 
 * Binary search tree definitions in C.
 * Activity/lesson 4 from "C for Java Programmers"
 */

typedef struct treenode *TreeNode;

extern TreeNode new_TreeNode(int val); // construct new node
extern void free_TreeNode(TreeNode this); // recursively free this node and all children

extern void TreeNode_print(TreeNode this); // recursively print info for this node and all children
