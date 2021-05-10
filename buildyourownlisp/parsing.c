/*
 * lisB (lisp by bol0gna)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <editline/readline.h>

#include "mpc.h"

/* carry out the specified option when evaluating expression */
long eval_op(char* op, long a, long b) {
	if (strlen(op) != 1) {
		return 0;
	}

	switch(op[0]) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
		case '%': return a % b;
		case '^': return (long)pow(a, b);
		default: return 0;
	}
}

long eval(mpc_ast_t* t) {
	/* number is always leaf node of AST so return the number */
	if (strstr(t->tag, "number")) {
		return atoi(t->contents);
	}

	/* op is second child of t node, first is ( last is ) */
	char* op = t->children[1]->contents;
	long a = eval(t->children[2]);

	/* evaluate all other sub-expressions of current, do specified op */
	for (int i = 3; strstr(t->children[i]->tag, "expr"); i++) {
		a = eval_op(op, a, eval(t->children[i]));
	}

	return a;
}

int main(int argc, char** argv) {
		/* create & define parsers for polish notation */
		mpc_parser_t* Number = mpc_new("number");
		mpc_parser_t* Operator = mpc_new("operator");
		mpc_parser_t* Expr = mpc_new("expr");
		mpc_parser_t* Lisp = mpc_new("lisp");

		mpca_lang(MPCA_LANG_DEFAULT,
			"													\
			number		: /-?[0-9]+/ ;							\
			operator	: '+' | '-' | '*' | '/' | '%' | '^' ;	\
			expr	: <number> | '(' <operator> <expr>+ ')' ;	\
			lisp		: /^/ <operator> <expr>+ /$/ ;			\
			",
			Number, Operator, Expr, Lisp);

	/* version and exit info */
	puts("lisB version 0.0.1, Ctrl+c to exit\n");

	while(1) {
		/* prompt and get input, add input to history */
		char* input = readline("lisB> ");
		add_history(input);

		/* parse input for polish notation, print AST on success */
		mpc_result_t r;
		if (mpc_parse("<stdin>", input, Lisp, &r)) {
			printf("%li\n", eval(r.output));
			mpc_ast_delete(r.output);
		} else {
			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}

		free(input);
	}

	/* undefine parsers */
	mpc_cleanup(4, Number, Operator, Expr, Lisp);

	return 0;
}
