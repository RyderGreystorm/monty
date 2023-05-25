#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * prt_str - funtion that prints the contents of a stack as a string
 * @stack: pointer to the stack
 * @line_number: line number for error messages
 *
 * Description: Prints the ASCII characters represented by the integer
 * values stored in the stack nodes,
 * up to a null byte or an invalid value.
 * The stack remains unchanged.
 *
 * Return: nothing
 */
void prt_str(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current_node = *stack;

	while (current_node)
	{
		if (current_node->n <= 0 || current_node->n > 127)
			break;
		putchar((char)current_node->n);
		current_node = current_node->next;
	}
	putchar('\n');
}
