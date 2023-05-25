#include "monty.h"
#include <stdio.h>

void rea_and_tokenize(char *filepath)
{
    FILE *file;
    char **args = NULL;
    unsigned int line_num = 0;
    int i;
    char *buffer = NULL;
    /*size_t n = 0;*/

    file = fopen(filepath, "r");

    /*check if it opened succesflly*/
    if (!file)
        err_message(filepath);
    /*read from the file into a buffer*/
    while ((fgets(buffer, sizeof(buffer), file)) != NULL)
    {
        line_num++;
        args = tokenizeArgs(buffer);
        executeOpcode(args, line_num);
        /*free args from token*/

        for(i = 0; args[i] != NULL; i++)
            free(args[i]);
        free(args);

    }
    fclose(file);
}

void read_and_tokenize(char *filepath)
{
    FILE *file;
    char **args = NULL;
    unsigned int line_num = 0;
    int i;
    char *buffer = NULL;
    size_t buffer_size = 0;

    file = fopen(filepath, "r");

    if (!file)
        err_message(filepath);

    while (getline(&buffer, &buffer_size, file) != -1)
    {
        line_num++;
        args = tokenizeArgs(buffer);
        executeOpcode(args, line_num);

        for (i = 0; args[i] != NULL; i++)
            free(args[i]);
        free(args);
    }

    fclose(file);
    free(buffer);
}