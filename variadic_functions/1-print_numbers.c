#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - prints numbers separated by a string
 * @separator: string printed between numbers
 * @n: number of integer arguments
 *
 * Return: Nothing.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list arguments;
	unsigned int i;

	va_start(arguments, n);

	i = 0;
	while (i < n)
	{
		if (i > 0 && separator != NULL)
		{
			printf("%s", separator);
		}

		i = va_arg(n, int)
		printf("%d", va_arg(arguments, int));
		i++;
	}

	printf("\n");
	va_end(arguments);
}
