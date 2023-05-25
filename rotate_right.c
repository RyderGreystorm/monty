#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * rotate_right - Rotates the last node of a stack to the top position
 * @stack: Pointer to the stack
 * @line_number: Line number for error messages
 *
 * Description: If the stack is not empty and has more than one element,
 * this function rotates the last node to the top position in the stack.
 * The rotation is done by updating the pointers accordingly.
 *
 * Return: nothing
 */
void rotate_right(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	stack_t *prev;

	(void) line_number;

	if (!stack || !(*stack) || !((*stack)->next))
		return;

	last = *stack;

	/*move last pointer to next node*/
	while (last->next)
		last = last->next;

	prev = last->prev;
	last->next = *stack;
	last->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = last;
	*stack = last;
}
