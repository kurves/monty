#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * executemonty - function to execute monty
 * @filename: name of file
 * Description: function to execute monty files
 * Return: nothing
 */
void executemonty(stack_t *stack,const char *filename)
{
	FILE *file = fopen(filename, "r");
	char opcode[10];
	int line_number = 1;
	int value;

	if (file == NULL)
	{
		printf("Error: Can't open file monty\n");
		exit(EXIT_FAILURE);
	}
	while (fscanf(file, "%s", opcode) == 1)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) != 1)
			{
				printf("Error: Invalid instruction format on line %d\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, value);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack);
		}
		else
		{
			printf("Error: L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	free(line);
	fclose(file);
	return (0);
}
}
