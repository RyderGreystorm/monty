#include "monty.h"

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
    if (lineptr == NULL || n == NULL || stream == NULL)
        return -1;

    ssize_t read_bytes = 0;
    ssize_t total_bytes = 0;
    int c;

    // Allocate initial buffer if needed
    if (*lineptr == NULL || *n == 0)
    {
        *n = 128; // Initial buffer size
        *lineptr = malloc(*n);
        if (*lineptr == NULL)
            return -1;
    }

    // Read characters until end of line or end of file
    while ((c = fgetc(stream)) != EOF)
    {
        if (total_bytes >= *n - 1) // Need to expand the buffer
        {
            *n *= 2; // Double the buffer size
            char *new_lineptr = malloc(*n);
            if (new_lineptr == NULL)
            {
                free(*lineptr);
                return -1;
            }

            // Copy the contents of the old buffer to the new buffer
            for (ssize_t i = 0; i < total_bytes; i++)
                new_lineptr[i] = (*lineptr)[i];

            free(*lineptr);
            *lineptr = new_lineptr;
        }

        (*lineptr)[total_bytes++] = (char)c;

        if (c == '\n')
            break;
    }

    if (total_bytes == 0) // Nothing read, reached end of file
        return -1;

    (*lineptr)[total_bytes] = '\0'; // Null-terminate the string
    return total_bytes;
}
