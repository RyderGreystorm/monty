#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * swap - function that Swaps the data of the top two nodes in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number for error messages
 *
 * Description: This function swaps the data of the top two nodes in the stack.
 * If the stack has fewer than two nodes, an error message is printed and the
 * program exits with failure.
 *
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = NULL;
	int tmp;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	tmp = top->n;
	top->n = top->next->n;
	top->next->n = tmp;
}

