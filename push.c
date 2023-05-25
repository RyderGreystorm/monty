#include "monty.h"

void push(stack_t **stack, unsigned int line_num  __attribute__((unused)))
{
    char * var_str = NULL;
    stack_t *new_node = NULL;
    int value;

    var_str = strtok(NULL, " ");

    if (!var_str)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_num);
        exit(EXIT_FAILURE);
    }
    /*Converting args to int*/
    value = atoi(var_str);
    /*Creating the new node */
    new_node = malloc(sizeof(stack_t));
    /*check failure*/
    if (new_node == NULL)
        malloc_failure();
    /*handle stack operation on list*/
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack == NULL)
        (*stack)->prev = new_node;
    *stack = new_node;
}