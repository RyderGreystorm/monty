#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * rotate_left - Rotates the first element of the stack to the last position
 * @stack: Pointer to the stack
 * @line_number: Line number for error messages
 *
 * Description: If the stack is not empty and has more than one element,
 * this function rotates the first element to the last position in the stack.
 * The rotation is done by updating the pointers accordingly.
 *
 * Return: nothing
 */
void rotate_left(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *last;

	(void) line_number;

	if (!stack || !(*stack) || !((*stack)->next))
		return;

	first = last = *stack;

	/*move the last pointer to the last node*/
	while (last->next)
		last = last->next;

	/* create a circular linked list loop*/
	last->next = first;
	first->prev = last;

	*stack = first->next;

	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

