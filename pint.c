#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * pint - function to print all elements
 * @stack: stack value
 * @line_number: line nuber to add at
 * Description: function to print all elements
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
