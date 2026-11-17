#include "variadic_functions.h"

/**
 * print_strings - Checks if a character is lowercase
 * @separator: Character to check
 * @n: est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list argus;
	char *textuss;

	va_start(argus, n);

	for (i = 0; i < n; i++)
	{
		textuss = va_arg(argus, char*);

		if (textuss == NULL)
		{
			printf("(nil)");
		}

		printf("%s", textuss);

		if (separator != NULL && i != n - 1)
		{
			printf("%s", separator);
		}
	}

	printf("\n");
	va_end(argus);
}
