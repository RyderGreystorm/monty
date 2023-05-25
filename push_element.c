#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

/**
 * push - function that pushes an element onto the stack
 * @stack: Pointer to the stack
 * @line_number: Line number for error messages
 *
 * Description: Pushes the integer value specified by
 * the argument onto the stack.
 * The argument must be a valid integer.
 * The behavior of the push operation depends on the data structure type.
 * If the data structure type is stack, the element is added,
 * as the top of the stack.
 * If the data structure type is queue, the element is added,
 * at the end of the stack.
 * If the argument is not a valid integer, an error message is printed.
 *
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *argument = global.argument;

	if ((is_digit(argument)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!addNode(stack, atoi(argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}

