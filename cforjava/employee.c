#include <stdlib.h>
#include <stdio.h>

typedef struct employee {
	char* name;
	int id;
} Employee;

unsigned long strlen(const char* str) {
	int len = 0;
	for (int i = 0; str[i] != 0; i++) {
		len++;
	}
	return len;
}

char* strcpy(char* cpy, const char* s) {
	for (int i = 0; s[i] != 0; i++) {
		cpy[i] = s[i];
	}
	return cpy;
}

char* strdup(const char* s) {
	char* dup = (char*)malloc(sizeof(strlen(s)+1));
	strcpy(dup, s);
	return dup;
}

Employee* new_Employee(const char* name, const int id) {
	Employee* this = (Employee*)malloc(sizeof(Employee));
	if (this == NULL) {
		return NULL; // out of memory
	}

	this->name = strdup(name);
	this->id = id;
	
	return this;
}

void Employee_free(Employee* this) {
	free(this->name);
	free(this);
}

void Employee_print(const Employee* this) {
	printf("Employee[%s,%d]", this->name, this->id);
}

char* Employee_getName(const Employee* this) {
	return this->name;
}

void Employee_setName(Employee* this, char* name) {
	this->name = strdup(name);
}

int Employee_getID(const Employee* this) {
	return this->id;
}

void Employee_setID(Employee* this, int id) {
	this->id = id;
}

int main(int argc, char* argv[]) {
	Employee* john = new_Employee("John Doe", 12345);
	Employee* jane = new_Employee("Jane Doe", 54321);

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
