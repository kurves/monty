#include <stdio.h> 
#include "monty.h"
#include <stdlib.h>

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file
 *
 * Description: The top element becomes the second top element,
 * and the second top element becomes the top element.
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	temp->prev = NULL;
	
	if ((*stack)->next != NULL)
		(*stack)->next->prev = *stack;
	*stack = temp;
}
