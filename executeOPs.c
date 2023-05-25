#include "monty.h"

void executeOpcode(char **args, unsigned int line_num)
{
    stack_t *stack = NULL;
    char *opcode = NULL;
    int i;
    bool opcodeFound;

    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };

    opcode = args[0];
    opcodeFound = false;
    for (i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(&stack, line_num);
            opcodeFound = true;
            break;
        }
    }
    if (!opcodeFound)
    {
        fprintf(stderr, "L%u: unknown instruction %s", line_num, opcode);
        exit(EXIT_FAILURE);
    }
}