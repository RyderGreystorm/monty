#include "monty.h"

/**
 * my_isascii - function that checks for ASCII chars
 * @c: char to check
 *
 * Return: nothing
 */

int my_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
