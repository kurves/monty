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
	stack_t *my_stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	executemonty(&my_stack, argv[1]);
	return (EXIT_SUCCESS);
}

