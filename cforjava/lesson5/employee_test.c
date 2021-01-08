/* test program for Employee class */

#include <stdio.h>
#include "employee.h"

int main(int argc, char* argv[]) {
	Employee john = new_Employee("John Doe", 12345);
	Employee jane = new_Employee("Jane Doe", 54321);

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

	Employee_free(john);
	Employee_free(jane);
}
