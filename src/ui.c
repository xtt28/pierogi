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
	return -1;
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
				printf("%f\n", stack_peek(st));
				break;
			case ERR_STACK_INCOMPLETE:
				puts("Not enough values in stack");
				break;
			case ERR_DIV_ZERO:
				puts("Cannot divide by zero");
				break;
			case ERR_UNRECOGNIZED_OP:
				puts("Unrecognized operation");
				break;
			default:
				break;
			}
		}
	}

	stack_free(st);
	return result;
}
