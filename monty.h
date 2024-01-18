#ifndef MONTY_H
#define MONTY_H
#include "instructions.h"
void pint(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, int value, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
#endif
