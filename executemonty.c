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
void executemonty(stack_t **stack,const char *filename)
{
	FILE *file = fopen(filename, "r");
	char opcode[10];
	int line_number = 1;
	int value;
	char *line = NULL;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n",filename);
		exit(EXIT_FAILURE);
	}
	while (fscanf(file, "%s", opcode) == 1)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) != 1)
			{
				fprintf(stderr, "Error: Invalid instruction format on line %d\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(stack, value);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "Error: L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		if (line == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	free(line);
	fclose(file);
}
