#include <stdio.h>
#include "monty.h"

/**
 * pall - function that prints the elements of the stack
 * @stack: Pointer to the stack
 * @lineNumber: Line number (unused)
 *
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int lineNumber __attribute__((unused)))
{
	printStack(*stack);
}

