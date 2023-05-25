#include "monty.h"

void pall(stack_t **stack, unsigned int line_num  __attribute__((unused)))
{
    stack_t *current = NULL;
    
    current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}