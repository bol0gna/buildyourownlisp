/* test program for Employee class */

#include <stdio.h>
#include "employee.h"
#include "linkedlist.h"

void printList(LinkedList list) {
	LinkedList_print(list);
	printf(" length %d", LinkedList_length(list));
}

int main(int argc, char* argv[]) {
	Employee john = new_Employee("John Doe", 12345);
	Employee jane = new_Employee("Jane Doe", 54321);
	Employee jeff = new_Employee("Jeff", 1);

	Employee_print(john);
	printf("\n");
	Employee_setID(john, 123);
	Employee_print(john);
	printf("\n");

	Employee_print(jane);
	printf("\n");
	Employee_setName(jane, "Jane Smith");
	Employee_print(jane);
	printf("\n");

	printf("%p ", john);
	printf("%p ", jane);
	printf("%p\n", jeff);

	LinkedList list = new_LinkedList();
	LinkedList_prepend(list, jane);
	LinkedList_prepend(list, jeff);
	LinkedList_append(list, john);
	printList(list);
}

