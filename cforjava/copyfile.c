#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		puts("only 2 arguments accepted, source file followed by destination file");
		return 1;
	}

	FILE* src = fopen(argv[1], "r");
	if (src == NULL) {
		puts("failed to open source file");
		return 1;
	}

	FILE* dest = fopen(argv[2], "w");
	if (dest == NULL) {
		puts("failed to open destination file");
		return 1;
	}

	while (!feof(src)) {
		char input[256];
		if (fgets(input, 255, src) != NULL) {
			fprintf(dest, "%s", input);
		}
	}

	fclose(src);
	fclose(dest);
	return 0;
}
