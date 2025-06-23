#define _USE_MATH_DEFINES

#include <math.h>

#include "calc.h"
#include "stack.h"

const size_t min_args[OP_COUNT] = {
	[OP_ADD] = 2,
	[OP_SUBTRACT] = 2,
	[OP_MULTIPLY] = 2,
	[OP_DIVIDE] = 2,
	[OP_PI] = 0,
	[OP_E] = 0,
	[OP_POW] = 2,
};

int operation_apply(stack *st, operation op)
{
	if (op >= OP_COUNT || op < 0)
	{
		return ERR_UNRECOGNIZED_OP;
	}
	if (st->len < min_args[op])
	{
		return ERR_STACK_INCOMPLETE;
	}
	
	switch (op)
	{
	case OP_ADD: {
		double b = stack_pop(st), a = stack_pop(st);
		stack_push(st, a + b);
		return SUCCESS;
	}
	case OP_SUBTRACT: {
		double b = stack_pop(st), a = stack_pop(st);
		stack_push(st, a - b);
		return SUCCESS;
	}
	case OP_MULTIPLY: {
		double b = stack_pop(st), a = stack_pop(st);
		stack_push(st, a * b);
		return SUCCESS;
	}
	case OP_DIVIDE: {
		double b = stack_pop(st), a = stack_pop(st);
		if (b == 0)
		{
			return ERR_DIV_ZERO;
		}
		stack_push(st, a / b);
		return SUCCESS;
	}
	case OP_PI:
		stack_push(st, M_PI);
	        return SUCCESS;
	case OP_E:
		stack_push(st, M_E);
		return SUCCESS;
	case OP_POW: {
		double b = stack_pop(st), a = stack_pop(st);
		stack_push(st, pow(a, b));
		return SUCCESS;
	}
	default:
		return ERR_UNRECOGNIZED_OP;
	}
}
