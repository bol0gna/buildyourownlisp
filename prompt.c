/*
 * lisB (lisp by bol0gna) REPL shell
 */

#include <stdlib.h>
#include <stdio.h>

/* if compiling on windows, replace editline functions with fakes */
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

char* readline(char* prompt) {
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	char* cpy = malloc(strlen(buffer)+1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}

void add_history(char* unused) {}

/* if compiling on unix, include editline functions */
#else
#include <editline/readline.h>
#endif

int main(int argc, char** argv) {

	/* version and exit info */
	puts("lisB version 0.0.2, Ctrl+c to exit\n");

	while(1) {

		/* prompt and get input, add input to history */
		char* input = readline("lisB> ");
		add_history(input);

		printf("no, you're a %s\n", input);

		free(input);

	}

	return 0;
}
