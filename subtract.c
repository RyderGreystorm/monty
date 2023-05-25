#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * subtract - function that subtracts the first two nodes of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number for error messages
 *
 * Description: This function subtracts the value of the second node from
 * the value of the first node in the stack.
 * The result is stored in the first node,
 * and the second node is removed from the stack.
 *
 * Return: nothing
 */
void subtract(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) - ((*stack)->n);
	/* removes the top node */
	pop(stack, line_number);
	(*stack)->n = result;
}
