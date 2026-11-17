#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Checks if a character is lowercase
 * @n: Character to check
 * ...: est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int temp = 0;
	va_list ags;

	if (n == 0)
	{
		return (0);
	}

	va_start(ags, n);

	for (i = 0; i < n; i++)
	{
		temp = temp + va_arg(ags, int);
	}

	va_end(ags);
	return (temp);

}
