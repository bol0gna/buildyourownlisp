/* 
 * array.c, not part of buildyourownlisp but i wanted to do an array thing
 */

#include <stdio.h>

void printArr(int a[], int sz) {
	for (int i = 0; i < sz; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void printStrReverse(char str[], int sz) {
	for (int i = sz-1; i >= 0; i--) {
		printf("%c", str[i]);
	}
	printf("\n");
}

int main(int argc, char** argv) {
	int ints[] = {5, 4, 3, 2, 1};
	char str[] = "hello";

	printArr(ints, sizeof ints / sizeof ints[0]);
	printStrReverse(str, sizeof str / sizeof str[0]);

	return 0;
}
