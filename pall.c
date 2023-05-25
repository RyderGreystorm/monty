#include <stdio.h>
#include "monty.h"

/**
 * prtStack - Prints the elements of the stack
 * @stack: Pointer to the stack
 * @lineNumber: Line number (unused)
 *
 * Return: nothing
 */
void prtStack(stack_t **stack, unsigned int lineNumber __attribute__((unused)))
{
	printStack(*stack);
}

