#include "monty.h"

int main(int argc, char **argv)
{
    char *filepath;
    if (argc != 2)
    {
        fprintf(stderr ,"USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    filepath = argv[1];
    read_and_tokenize(filepath);
    return (0);
}