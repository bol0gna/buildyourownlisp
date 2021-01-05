#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char input[256];

	while (1) {
		printf("enter text 255 chars or less, type quit and press enter to quit: ");
		fgets(input, 255, stdin);
		if (!strcmp(input, "quit\n")) {
			break;
		} else {
			printf("you said %s", input);
		}
	}

	return 0;
}
