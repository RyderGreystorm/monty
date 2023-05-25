#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
* divideTopTwoValues - Divides the second top value by the top value
* @stack: Pointer to the stack
* @lineNumber: Current line number
*
* Return: nothing
*/
void divideTopTwoValues(stack_t **stack, unsigned int lineNumber)
{
	int result;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't divide, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;
	pop(stack, lineNumber); /* Remove top node */
	(*stack)->n = result;
}
