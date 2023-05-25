#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * addTopTwoValues - function that adds the first two nodes of the stack
 * @stack: Pointer to the stack
 * @lineNumber: Current line number
 *
 * Return: nothing
*/
void addTopTwoValues(stack_t **stack, unsigned int lineNumber)
{
	int result;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, lineNumber); /* Remove top node */
	(*stack)->n = result;
}
