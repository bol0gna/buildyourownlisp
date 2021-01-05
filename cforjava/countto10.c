#include <stdio.h>

int main(int argc, char* argv[]) {
	for (int i = 1; i <= 10; i++) {
		printf("%d ", i);
	}
	printf("\n");

	for (int i = 10; i >= 1; i -= 2) {
		printf("%d ", i);
	}
	printf("\n");
}
