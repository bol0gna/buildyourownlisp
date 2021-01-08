/* implementation for linked list and list node classes */

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

Node new_Node(void* val) {
	Node this = (Node)malloc(sizeof(struct node));
	if (this == NULL) return this; // out of memory
	this->info = val;
	this->next = NULL;
	return this;
}

void Node_printList(Node this) {
	if (this != NULL) {
		printf("%p ", this->info);
		Node_printList(this->next);
	}
}

LinkedList new_LinkedList() {
	LinkedList this = (LinkedList)malloc(sizeof(struct linkedlist));
	if (this == NULL) return this; // out of memory
	this->head = NULL;
	this->tail = NULL;
	this->length = 0;
	return this;
}

void LinkedList_prepend(LinkedList this, void* val) {
	Node item = new_Node(val);
	if (item == NULL) return; // out of memory
	this->length++;
	if (this->length == 1) {
		this->tail = item; // adding to an empty list
	} else {
		item->next = this->head;
	}
	this->head = item;
}

void LinkedList_append(LinkedList this, void* val) {
	Node item = new_Node(val);
	if (item == NULL) return; // out of memory
	this->length++;
	if (this->length == 1) {
		this->head = item; // adding to an empty list
	} else {
		this->tail->next = item;
	}
	this->tail = item;
}

int LinkedList_length(LinkedList this) {
	return this->length;
}

void* LinkedList_first(LinkedList this) {
	if (this->head == NULL) {
		return NULL;
	} else {
		return this->head->info;
	}
}

void* LinkedList_last(LinkedList this) {
	if (this->tail == NULL) {
		return NULL;
	} else {
		return this->tail->info;
	}
}

void LinkedList_print(LinkedList this) {
	Node_printList(this->head);
}
