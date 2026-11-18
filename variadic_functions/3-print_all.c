#include "variadic_functions.h"

/**
 * pass - Checks if a character is lowercase
 * @agiz: Character to check
 * @sep: est un pointeur de fonction
 * @format: est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */

void pass(char format, va_list *agiz, char **sep)
{
	char *textuss;

	switch (format)
			{
				case 'i':
				printf("%s%d", *sep, va_arg(*agiz, int));
				*sep = ", ";
				break;

				case 'f':
				printf("%s%f", *sep, va_arg(*agiz, double));
				*sep = ", ";
				break;

				case 'c':
				printf("%s%c", *sep, va_arg(*agiz, int));
				*sep = ", ";
				break;

				case 's':
				textuss = va_arg(*agiz, char*);
				if (textuss == NULL)
				{
					textuss = "(nil)";
				}
				printf("%s%s", *sep, textuss);
				*sep = ", ";
				break;

				default:
				break;
			}
}

/**
 * print_all - Checks if a character is lowercase
 * @format: Character to check
 * : est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */
void print_all(const char * const format, ...)
{
	va_list agiz;
	int j = 0;
	char *sep = "";

	va_start(agiz, format);

	if (format != NULL)
	{

		while (format[j] != '\0')
		{
			pass(format[j], &agiz, &sep);
			j++;
		}
	}

	va_end(agiz);
	printf("\n");
}
