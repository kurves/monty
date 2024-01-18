#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * executemonty - function to execute monty
 * @filename: name of file
 * Description: function to execute monty files
 * Return: nothing
 */
int executemonty(stack_t **stack, const char *opcode, int value, unsigned int line_number, FILE *file)
{
	if (strcmp(opcode, "push") == 0)
	{
		if (fscanf(file, "%d", &value) != 1)
		{
			fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push(stack, value, line_number);
		return (1);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
		return (1);
	}
	return (0);
}
