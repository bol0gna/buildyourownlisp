/*
 * lisB (lisp by bol0gna)
 * version 0.0.1
 */

#include <stdio.h>

/* user input buffer, max size 2048 */
static char input[2048];

int main(int argc, char** argv) {

	/* version and exit info */
	puts("lisB version 0.0.1, Ctrl+c to exit\n");

	while(1) {

		/* prompt */
		fputs("lisB> ", stdout);

		/* read line of user input (length <= max size) into buffer */
		fgets(input, 2048, stdin);

		printf("no, you're a %s", input);
	}

	return 0;
}
