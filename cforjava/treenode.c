/* 
 * Binary search tree implementation in C.
 * Activity/lesson 4 from "C for Java Programmers"
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct node* Node;
struct node {
	int info;
	Node left;
	Node right;
};

/* allocate and initialize new node with an int value to store */
Node new_Node(int val) {
	Node this = (Node)malloc(sizeof(struct node));
	if (this == NULL) {
		return NULL; // out of memory
	}

	this->info = val;
	this->left = NULL;
	this->right = NULL;

	return this;
}

/* recursively free this node and all children */
void free_Node(Node this) {
	if (this == NULL) return;
	if (this->left == NULL && this->right == NULL) {
		free(this);
		return;
	}
	free_Node(this->left);
	free_Node(this->right);
}

/* print this node only */
void Node_print(Node this) {
	if (this != NULL) {
		printf("Node[%d]", this->info);
	}
}

/* recursively print this node and all children, in-order traversal */
void Node_treeprint(Node this) {
	if (this != NULL) {
		Node_treeprint(this->left);
		Node_print(this);
		Node_treeprint(this->right);
	}
}

/* add a value to the binary search tree rooted at this node */
Node Node_add(Node this, int val) {
	if (this == NULL) {
		this = new_Node(val);
	} else if (val < this->info) {
		this->left = Node_add(this->left, val);
	} else if (val > this->info) {
		this->right = Node_add(this->right, val);
	} // no action taken if val is already in tree
	return this;
}

/* lookup a value using binary search tree return whether value is in tree */
int Node_lookup(Node this, int val) {
	if (this == NULL) {
		return 0;
	} else if (val < this->info) {
		return Node_lookup(this->left, val);
	} else if (val > this->info) {
		return Node_lookup(this->right, val);
	} else {
		return 1;
	}
}

/* apply void function(int) referenced by fp to each value in sorted order */
void Node_apply(Node this, void (*fp)(int)) {
	if (this != NULL) {
		Node_apply(this->left, fp);
		(*fp)(this->info);
		Node_apply(this->right, fp);
	}
}

typedef struct tree* Tree;
struct tree {
	Node root;
};

Tree new_Tree() {
	Tree this = (Tree)malloc(sizeof(struct tree));
	if (this == NULL) return this;
	this->root = NULL;
	return this;
}

void Tree_print(Tree this) {
	Node_treeprint(this->root);
}

void Tree_add(Tree this, int val) {
	this->root = Node_add(this->root, val);
}

int Tree_lookup(Tree this, int val) {
	return Node_lookup(this->root, val);
}

void Tree_apply(Tree this, void (*fp)(int)) {
	Node_apply(this->root, fp);
}

void callbackTest(int val) {
	printf("%d ", val);
}

int main(int argc, char* argv[]) {
	Node a = new_Node(123);
	Node b = new_Node(7);
	Node c = new_Node(1);

	Node_print(a);
	Node_print(b);
	Node_print(c);
	printf("\n");

	b->right = a;
	c->right = b;
	Node_treeprint(c);
	printf("\n");

	Node d = Node_add(NULL, 5);
	Node_add(d, 6);
	Node_add(d, 2);
	Node_add(d, 1);
	Node_add(d, 5);

	Node_treeprint(d);
	printf("\n");

	Tree h = new_Tree();
	Tree_add(h, 1);
	Tree_add(h, 2);
	Tree_add(h, 4);
	Tree_add(h, 3);
	Tree_print(h);
	printf("\n");

	printf("3 in tree: %d\n5 in tree: %d\n", Tree_lookup(h, 3), Tree_lookup(h, 5));

	Tree_apply(h, &callbackTest);
	printf("\n");
}
