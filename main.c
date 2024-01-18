#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>

/**
 * main - mai entry point
 * @argc: number of arguments]
 * @argv: array of arguments
 * Description: program entry point
 * Return: integer value
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file;
	char opcode[10];
	int value;
	unsigned int line_number;
	line_number = 1;
	value = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fscanf(file, "%s", opcode) == 1)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) != 1)
			{
				fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, value, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		line_number++;
	}
	fclose(file);
	return (EXIT_SUCCESS);
}

