/* test program for Employee class */

#include <stdio.h>
#include "employee.h"
#include "linkedlist.h"
#include "employeelist.h"

void printList(EmployeeList list) {
	EmployeeList_print(list);
	printf("length %d", EmployeeList_length(list));
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

	EmployeeList list = new_EmployeeList();
	EmployeeList_prepend(list, jane);
	EmployeeList_prepend(list, jeff);
	EmployeeList_append(list, john);
	printList(list);
}

