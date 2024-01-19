#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <ctype.h>
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
	char str[20];
	size_t i;
	stack_t *new_node = malloc(sizeof(stack_t));
	
	sprintf(str, "%d", value);

	for (i = 0; i < strlen(str); i++)
	{
		if (!isdigit(str[i]) && (i == 0 && str[i] != '-'))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
	
}
/**
 * freeStack - frees stack
 * @stack: Double pointer to the head of the stack
 * Description: function to free stack
 * Return: nothing
 */
void freeStack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
}
/**
 * unknownCommand - handle unknown commands
 * @line_number: line number
 * @command: keyed in command
 * Description: function to handle unknown commands
 * Return: nothing
 */
void unknownCommand(int line_number, const char *command)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
}
