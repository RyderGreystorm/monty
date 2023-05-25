#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

/**
 * is_digit - function that Checks if a string represents a valid digit
 * @string: String to check
 *
 * Return: 1 if the string is a digit,
 *	0 otherwise
 */
int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);

	if (*string == '-')
		string++;

	while (*string)
	{
		if (!isdigit(*string))
			return (0);
		string++;
	}

	return (1);
}

/**
 * is_number - function that Checks if a string represents a valid number
 * @str: Provided string
 *
 * Return: 1 if the string is a number,
 *	0 otherwise
 */
int is_number(char *str)
{
	int t;

	if (!str)
		return (0);

	for (t = 0; str[t]; t++)
	{
		if (str[t] < '0' || str[t] > '9')
			return (0);
	}

	return (1);
}
