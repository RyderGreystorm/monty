#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * pop - function that pops the very top element of the stack, without deleting
 * @stack: pointer to stack
 * @line_count: number of lines
 *
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_count)
{
	/*initialize stack*/
	stack_t *temp = NULL;

	/*compare operands, top and bottom element*/
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_count);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;

	if (!*stack)
		return;

	(*stack)->prev = NULL;
}

