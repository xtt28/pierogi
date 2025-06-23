#include <stdio.h>

#include "stack.h"

void stack_expand(stack *st)
{
	st->capacity *= 2;
	st->values = realloc(st->values, st->capacity * sizeof(double));
}

double stack_push(stack *st, double value)
{
	if (st->len >= st->capacity)
	{
		stack_expand(st);
	}
	st->values[st->len++] = value;
	
	return value;
}

double stack_pop(stack *st)
{
	double tmp = st->values[st->len - 1];
	st->values[st->len - 1] = 0;
	st->len--;

	return tmp;
}

double stack_peek(stack *st) { return st->values[st->len - 1]; }

void stack_print(stack *st)
{
	putchar('(');
	for (size_t i = 0; i < st->len; ++i)
	{
		printf("%f", st->values[i]);
		if (i != st->len - 1)
		{
			putchar(' ');
		}
	}
	printf(")\n\n");
}

stack *stack_create(void)
{
	stack *st = malloc(sizeof(stack));
	st->len = 0;
	st->values = malloc(sizeof(double));
	st->capacity = 1;

	return st;
}

void stack_free(stack *st)
{
	free(st->values);
	free(st);
}
