/* 
 * Binary search tree implementation in C.
 * Activity/lesson 4 from "C for Java Programmers"
 */

#include <stdlib.h>
#include <stdio.h>

struct node {
	int info;
	struct node* left;
	struct node* right;
};

struct node* new_node(int val) {
	struct node* this = (struct node*)malloc(sizeof(struct node));
	if (this == NULL) {
		return NULL; // out of memory
	}

	this->info = val;
	this->left = NULL;
	this->right = NULL;

	return this;
}

void free_node(struct node* this) {
	if (this == NULL) return;
	if (this->left == NULL && this->right == NULL) {
		free(this);
		return;
	}
	free_node(this->left);
	free_node(this->right);
}

void node_print(struct node* this) {
	if (this != NULL) {
		printf("Node[%d]", this->info);
	}
}

void node_treeprint(struct node* this) {
	if (this != NULL) {
		node_treeprint(this->left);
		node_print(this);
		node_treeprint(this->right);
	}
}

int main(int argc, char* argv[]) {
	struct node* a = new_node(123);
	struct node* b = new_node(7);
	struct node* c = new_node(1);

	node_print(a);
	node_print(b);
	node_print(c);
	printf("\n");

	b->right = a;
	c->right = b;
	node_treeprint(c);
	printf("\n");
}
