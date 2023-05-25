#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INSTRUCTIONS              \
	{                           \
		{"push", push},       \
		    {"pall", pall},   \
		    {"pint", pint},   \
		    {"pop", pop},     \
		    {"swap", swap},   \
		    {"nop", nop},     \
		    {"div", _div},    \
		    {"mul", _mul},    \
		    {"add", _add},    \
		    {"sub", _sub},    \
		    {"calculateMod", calculateMod},     \
		    {"printChar", printChar}, \
		    {"prt_str", prt_str},   \
		    {"rotate_left", rotate_left},   \
		    {"rotate_right", rotate_right},   \
		{                     \
			NULL, NULL      \
		}                     \
	}

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct help - argument for the current opcode
* @data_struct: stack mode, stack (default) and queue
* @argument: the arguments of the string
*
* Description: global structure used to pass data around the functions easily
*/
typedef struct help
{
	int data_struct;
	char *argument;
} help;
help global;

/* stack utility functions available in list.c */
stack_t *addNode(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);
void freeStack(stack_t *stack);
size_t printStack(const stack_t *stack);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int lineNumber);
void pint(stack_t **stack, unsigned int lineNumber);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_count);
void nop(stack_t **stack, unsigned int lineNumber);

void _div(stack_t **stack, unsigned int lineNumber);
void _add(stack_t **stack, unsigned int lineNumber);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int lineNumber);
void calculateMod(stack_t **stack, unsigned int lineNumber);

void printChar(stack_t **stack, unsigned int lineNumber);
void prt_str(stack_t **stack, unsigned int line_number);
void rotate_left(stack_t **stack, unsigned int line_number);
void rotate_right(stack_t **stack, unsigned int line_number);

void opcode(stack_t **stack, char *str, unsigned int lineNumber);

int is_digit(char *string);
int is_number(char *str);
int my_isascii(int c);

#endif /* MONTY_H */
