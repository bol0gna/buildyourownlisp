#include <stdio.h>

void hello(int n) {
	for (int i = 0; i < n; i++) {
		puts("hello, world");
	}
}

int main(int argc, char** argv) {
	puts("while loop");
	int i = 0;
	while (i < 5) {
		puts("hello, world");
		i++;
	}

	puts("\nfor loop");
	for (int i = 0; i < 5; i++) {
		puts("hello, world");
	}

	puts("\nhello(3)");
	hello(3);

	return 0;
}
