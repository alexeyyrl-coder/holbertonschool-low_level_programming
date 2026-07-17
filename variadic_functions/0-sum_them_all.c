#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum of its integer arguments
 * @n: number of integer arguments
 *
 * Return: sum of all arguments, or 0 if n is 0
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list arguments;
	unsigned int i;
	int sum;

	sum = 0;
	va_start(arguments, n);

	i = 0;
	while (i < n)
	{
		sum += va_arg(arguments, int);
		i++;
	}

	va_end(arguments);

	return (sum);
}
