#ifndef CALC_H
#define CALC_H

#include "stack.h"

#define SUCCESS 0
#define ERR_STACK_INCOMPLETE 1
#define ERR_DIV_ZERO 2
#define ERR_UNRECOGNIZED_OP 3

typedef enum { OP_ADD, OP_SUBTRACT, OP_MULTIPLY, OP_DIVIDE, OP_PI, OP_E, OP_POW, OP_SIN, OP_COS, OP_COUNT } operation;

int operation_apply(stack *st, operation op);

#endif
