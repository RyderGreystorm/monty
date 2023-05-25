#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./monty.h"

/**
 * opcode - function that executes the appropriate operation,
 * based on the given opcode
 *
 * @stack: Pointer to the stack
 * @str: Opcode to compare
 * @lineNumber: Line number
 *
 * Return: void
 */
void opcode(stack_t **stack, char *str, unsigned int lineNumber)
{
	int t = 0;

	instruction_t operations[] = INSTRUCTIONS;

	if (!strcmp(str, "stack"))
	{
		global.data_struct = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data_struct = 0;
		return;
	}

	while (operations[t].opcode)
	{
		if (strcmp(operations[t].opcode, str) == 0)
		{
			operations[t].f(stack, lineNumber);
			return;
		}
		t++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, str);
	exit(EXIT_FAILURE);
}

