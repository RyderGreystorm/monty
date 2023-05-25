#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * calculateMod - function that computes the remainder of the division
 * @stack: Pointer to the stack
 * @lineNumber: Current line number
 *
 * Return: nothing
 */
void calculateMod(stack_t **stack, unsigned int lineNumber)
{
	int result;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) % ((*stack)->n);
	/* remove the top node*/
	pop(stack, lineNumber);
	(*stack)->n = result;
}

