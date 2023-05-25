#include "monty.h"

/**
 * err_message - prints error message
 * @filepath: file it tried to read
*/

void err_message(char *filepath)
{
    fprintf(stderr, "Error: Can't open file %s\n", filepath);
    exit(EXIT_FAILURE);
}

void malloc_failure(void)
{
    fprintf(stderr, "Error: malloc failed");
    exit(EXIT_FAILURE);
}