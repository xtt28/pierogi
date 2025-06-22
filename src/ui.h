#ifndef UI_H
#define UI_H

#include <stdio.h>

#include "stack.h"
#include "calc.h"

#define TERM_BOLD "\033[1m"
#define TERM_RESET "\033[0m"

operation sign_to_op(const char *sign);
int run();

#endif
