#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_value - prints one argument according to its type
 * @type: type of the argument
 * @arguments: variadic argument list
 * @separator: string printed before valid arguments
 *
 * Return: Nothing.
 */
static void print_value(char type, va_list *arguments,
			const char **separator)
{
	char *string;

	switch (type)
	{
	case 'c':
		printf("%s%c", *separator, va_arg(*arguments, int));
		*separator = ", ";
		break;
	case 'i':
		printf("%s%d", *separator, va_arg(*arguments, int));
		*separator = ", ";
		break;
	case 'f':
		printf("%s%f", *separator, va_arg(*arguments, double));
		*separator = ", ";
		break;
	case 's':
		string = va_arg(*arguments, char *);
		if (string == NULL)
			string = "(nil)";
		printf("%s%s", *separator, string);
		*separator = ", ";
		break;
	default:
		break;
	}
}

/**
 * print_all - prints arguments according to a format
 * @format: list of argument types
 *
 * Return: Nothing.
 */
void print_all(const char * const format, ...)
{
	va_list arguments;
	unsigned int i;
	const char *separator;

	va_start(arguments, format);
	i = 0;
	separator = "";

	if (format != NULL)
	{
		while (format[i] != '\0')
		{
			print_value(format[i], &arguments, &separator);
			i++;
		}
	}

	va_end(arguments);
	printf("\n");
}
