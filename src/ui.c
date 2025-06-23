#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calc.h"
#include "stack.h"
#include "ui.h"

operation sign_to_op(const char *sign)
{
	if (strcmp(sign, "+") == 0) return OP_ADD;
	if (strcmp(sign, "-") == 0) return OP_SUBTRACT;
	if (strcmp(sign, "*") == 0) return OP_MULTIPLY;
	if (strcmp(sign, "/") == 0) return OP_DIVIDE;
	if (strcmp(sign, "pi") == 0) return OP_PI;
	if (strcmp(sign, "e") == 0) return OP_E;
	if (strcmp(sign, "^") == 0) return OP_POW;
	if (strcmp(sign, "sin") == 0) return OP_SIN;
	if (strcmp(sign, "cos") == 0) return OP_COS;
	return OP_COUNT;
}

int run()
{
	int result = 0;
	printf("%sWelcome to pierogi\n", TERM_BOLD);

	stack *st = stack_create();
	
	while (true)
	{
		printf(">> %s", TERM_RESET);
		char buffer[50];
		if (scanf("%49s", buffer) != true)
		{
			puts("Failed to read input.");
			result = 1;
			break;
		}

		char *endptr;

		if (strcmp(buffer, "exit") == 0)
		{
			puts("Bye bye.");
			break;
		}

		if (strcmp(buffer, "show") == 0)
		{
			stack_print(st);
			continue;
		}
		
		double val = strtod(buffer, &endptr);
		bool is_num = *endptr == '\0';
		if (is_num)
		{
			stack_push(st, val);
		}
		else
		{
			operation op = sign_to_op(buffer);
			int res = operation_apply(st, op);
			switch (res)
			{
			case SUCCESS:
				printf("%f\n\n", stack_peek(st));
				break;
			case ERR_STACK_INCOMPLETE:
				puts("Not enough values in stack\n");
				break;
			case ERR_DIV_ZERO:
				puts("Cannot divide by zero\n");
				break;
			case ERR_UNRECOGNIZED_OP:
				puts("Unrecognized operation\n");
				break;
			default:
				break;
			}
		}
	}

	stack_free(st);
	return result;
}
