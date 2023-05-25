#define  _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void handle_file_error(char *filename);
void print_error_usage(void);

/* Declare global variable */
int status = 0;

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: Exit status
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buffer_size = 0;
	char *buffer = NULL;
	char *token = NULL;
	stack_t *stack = NULL;
	unsigned int line_count = 1;

	global.data_struct = 1;

	if (argc != 2)
		print_error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		handle_file_error(argv[1]);

	while (getline(&buffer, &buffer_size, file) != -1)
	{
		if (status)
			break;

		if (*buffer == '\n')
		{
			line_count++;
			continue;
		}

		token = strtok(buffer, " \t\n");

		if (!token || *token == '#')
		{
			line_count++;
			continue;
		}

		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, token, line_count);
		line_count++;
	}

	free(buffer);
	freeStack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * handle_file_error - function that prints a file error message and exits
 * @filename: Name of the file
 *
 * Description: Prints an error message if it's not possible to open the file.
 * Exits the program with a failure status.
 *
 * Return: void
 */
void handle_file_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * print_error_usage - function that Prints a usage error message and exits
 *
 * Description: Prints a usage message when the user does not provide any file
 * or provides more than one argument to the program. Exits the program with
 * a failure status.
 *
 * Return: void
 */
void print_error_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

