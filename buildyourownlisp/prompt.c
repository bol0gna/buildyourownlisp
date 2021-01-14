/*
 * lisB (lisp by bol0gna)
 */

#include <stdlib.h>
#include <stdio.h>
#include <editline/readline.h>

int main(int argc, char** argv) {

	/* version and exit info */
	puts("lisB version 0.0.1, Ctrl+c to exit\n");

	while(1) {

		/* prompt and get input, add input to history */
		char* input = readline("lisB> ");
		add_history(input);

		printf("no, you're a %s\n", input);

		free(input);

	}

	return 0;
}
