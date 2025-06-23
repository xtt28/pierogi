#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct
{
	size_t len;
	size_t capacity;
	double *values;
} stack;

void stack_expand(stack *st);
double stack_push(stack *st, double value);
double stack_pop(stack *st);
double stack_peek(stack *st);
void stack_print(stack *st);
stack *stack_create(void);
void stack_free(stack *st);

#endif
