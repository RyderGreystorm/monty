#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pint - function that prints the value at the top of the stack
 * @stack: Pointer to the stack
 * @lineNumber: Line number
 *
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int lineNumber)
{
	/*compare two operands, top and bottom stack*/
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't print top value, stack empty\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
