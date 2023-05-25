#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

/**
 * printChar - Prints the character value at the top of the stack
 * @stack: Pointer to the stack
 * @lineNumber: Line number
 *
 * Return: nothing
 */

void printChar(stack_t **stack, unsigned int lineNumber)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't print char, stack empty\n", lineNumber);
		exit(EXIT_FAILURE);
		return;
	}
	if (my_isascii((*stack)->n) == 0)
	{
		/*character value print*/
		fprintf(stderr, "L%d: can't print char, value out of range\n", lineNumber);
		exit(EXIT_FAILURE); /*on error fail to print*/
		return;
	}
	printf("%c\n", (*stack)->n);
}
