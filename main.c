#include <stdio.h>
#include <stdlib.h>
#include "main.h"
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
	FILE *file = fopen("monty");
	char opcode[10];
	int line_number = 1;
	int value;

	if (file == null)
	{
		printf("Error: Can't open file monty\n");
		exit(EXIT_FAILURE);
	}
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
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
			push(&myStack, value);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&myStack);
		}
		else
		{
			printf("Error: L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	fclose(file);
	return (0);
}
}
