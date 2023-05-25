#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * queue_node - Creates a new node and adds it to the end of the stack
 * @stack: Pointer to the stack
 * @n: Value of the new node
 *
 * Return: Newly created node, or NULL if memory allocation fails
 */
stack_t *queue_node(stack_t **stack, const int n)
{
	stack_t *newNode = malloc(sizeof(stack_t));
	stack_t *currentNode = *stack;

	if (!newNode)
	{
		free(newNode);
		return (NULL);
	}
	newNode->n = n;

	if (!*stack)
	{
		newNode->next = NULL;
		newNode->prev = NULL;
		*stack = newNode;
		return (newNode);
	}

	while (currentNode)
	{
		if (!currentNode->next)
		{
			newNode->next = NULL;
			newNode->prev = currentNode;
			currentNode->next = newNode;
			break;
		}
		currentNode = currentNode->next;
	}

	return (newNode);
}

/**
 * addNode - Creates a new node and adds it to the start of the stack
 * @stack: Pointer to the stack
 * @n: Value of the new node
 *
 * Return: Newly created node,
 *	NULL if memory allocation fails
 */
stack_t *addNode(stack_t **stack, const int n)
{
	stack_t *newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(newNode);
		return (NULL);
	}
	newNode->n = n;

	newNode->next = *stack;
	newNode->prev = NULL;
	if (*stack)
		(*stack)->prev = newNode;

	*stack = newNode;

	return (newNode);
}

/**
 * printStack - Prints the contents of the stack
 * @stack: Pointer to the stack
 *
 * Return: Number of elements in the stack
 */
size_t printStack(const stack_t *stack)
{
	size_t count = 0;

	while (stack)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
		count++;
	}

	return (count);
}

/**
 * freeStack - Frees the memory allocated for the stack
 * @stack: Pointer to the stack
 *
 * Return: nothing
 */
void freeStack(stack_t *stack)
{
	stack_t *currentNode = stack;
	stack_t *nextNode;

	if (stack)
	{
		nextNode = stack->next;
		while (currentNode)
		{
			free(currentNode);
			currentNode = nextNode;
			if (nextNode)
			nextNode = nextNode->next;
		}
	}
}
