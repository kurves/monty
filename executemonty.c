#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.c"
#include "main.h"

/**
 * executemonty - function to execute monty
 * @filename: name of file
 * Description: function to execute monty files
 * Return: nothing
 */
void executemonty(const char *filename)
{
	FILE *file = fopen(filename, "r");
        char opcode[10];
        int line_number = 1;
        int value;

        if (file == null)
        {
                printf("Error: Can't open file monty\n");
                exit(EXIT_FAILURE);
        }
}
