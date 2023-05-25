#include "monty.h"
char *strdup(const char *str)
{
  size_t len = strlen(str);
  char *dup = malloc(len + 1);
  if (dup == NULL) {
    return NULL;
  }
  strcpy(dup, str);
  return dup;
}