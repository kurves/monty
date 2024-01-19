#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"
/**
 * pall - Prints all the values on the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file
 * Description: function to print all values
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pall, stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
