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
		if (!executemonty(&stack, opcode, value, line_number, file))
		{
			fprintf(stderr, "Error: L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	fclose(file);
	return (EXIT_SUCCESS);
}

