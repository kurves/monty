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
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	executemonty(argv[1]);
	return (0);
}

