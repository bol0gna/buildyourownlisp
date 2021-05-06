/*
 * lisB (lisp by bol0gna)
 */

#include <stdlib.h>
#include <stdio.h>
#include <editline/readline.h>

#include "mpc.h"

int main(int argc, char** argv) {
		/* create & define parsers for polish notation */
		mpc_parser_t* Number = mpc_new("number");
		mpc_parser_t* Operator = mpc_new("operator");
		mpc_parser_t* Expr = mpc_new("expr");
		mpc_parser_t* Lisp = mpc_new("lisp");

		mpca_lang(MPCA_LANG_DEFAULT,
			"													\
			number		: /-?[0-9]+/ ;							\
			operator	: '+' | '-' | '*' | '/' ;				\
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
			mpc_ast_print(r.output);
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
