#include "monty.h"

char **tokenizeArgs(const char *buffer)
{
    char *delim = " \n\t";
    char **args = NULL, **new_args = NULL;
    char *token = NULL;
    int num_token = 0;

    token = strtok((char*)buffer, delim);
    while (token != NULL)
    {
        num_token++;
        new_args = malloc(sizeof(char*) * num_token);
        if (new_args == NULL)
            malloc_failure();
        memcpy(new_args, args, sizeof(char*) * (num_token -1));
        new_args[num_token - 1] = strdup(token);
        if (new_args[num_token - 1] == NULL)
            malloc_failure();
        free(args);
        args = new_args;
        token = strtok(NULL, delim);
    }
    num_token++;
    args = malloc(sizeof(char*) * num_token);
    if (args == NULL)
        malloc_failure();
    memcpy(args, new_args, sizeof(char*) * (num_token - 1));
    args[num_token - 1] = NULL;
    return (args);
}