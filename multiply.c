#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * _mul - Multiplies the top two values of the stack
 * @stack: Pointer to the stack
 * @lineNumber: Current line number
 *
 * Return: nothing
 */
void _mul(stack_t **stack, unsigned int lineNumber)
{
	int result;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) * ((*stack)->n);
	/* Removes the top node*/
	pop(stack, lineNumber);
	(*stack)->n = result;
}
