#include "variadic_functions.h"

/**
 * print_name - Checks if a character is lowercase
 * @separator: Character to check
 * @n: est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list argus;

	va_start(argus, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", (va_arg(argus, int)));

		if (separator != NULL && i != n - 1)
		{
			printf("%s", separator);
		}
	}

	va_end(argus);
	printf("\n");
}
