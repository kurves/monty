#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * push - Pushes an element
 * @stack: Double pointer to the head of the stack
 * @value: Value to be pushed onto the stack
 * @line_number: Line number in the file
 * Description: function to push element
 * Return: struct value
 */
void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	(void)line_number;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 * freeStack - frees stack
 * @stack: Double pointer to the head of the stack
 * Description: function to free stack
 * Return: nothing
 */
void freeStack(stack_t **stack)
{
	(void)stack;
}
