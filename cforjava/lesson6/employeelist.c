/* implementation for EmployeeList class */

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"
#include "employee.h"
#include "employeelist.h"

struct elist {
	LinkedList list;
};

EmployeeList new_EmployeeList() {
	EmployeeList this = (EmployeeList)malloc(sizeof(struct elist));
	if (this == NULL) return NULL; // out of memory
	this->list = new_LinkedList();
	return this;
}

void EmployeeList_prepend(EmployeeList this, Employee val) {
	LinkedList_prepend(this->list, val);
}

void EmployeeList_append(EmployeeList this, Employee val) {
	LinkedList_append(this->list, val);
}

int EmployeeList_length(EmployeeList this) {
	return LinkedList_length(this->list);
}

Employee EmployeeList_first(EmployeeList this) {
	return (Employee)LinkedList_first(this->list);
}

Employee EmployeeList_last(EmployeeList this) {
	return (Employee)LinkedList_last(this->list);
}

void EmployeeList_print(EmployeeList this) {
	Node list = this->list->head;
	while (list != NULL) {
		Employee_print((Employee)(list->info));
		printf(" ");
		list = list->next;
	}
}
