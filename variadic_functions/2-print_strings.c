#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - prints strings separated by a string
 * @separator: string printed between each argument
 * @n: number of string arguments
 *
 * Return: Nothing.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list arguments;
	unsigned int i;
	char *string;

	va_start(arguments, n);

	i = 0;
	while (i < n)
	{
		if (i > 0 && separator != NULL)
		{
			printf("%s", separator);
		}

		string = va_arg(arguments, char *);

		if (string == NULL)
		{
			printf("%s", "(nil)");
		}
		else
		{
			printf("%s", string);
		}

		i++;
	}

	va_end(arguments);
	printf("\n");
}
