#include "main.h"

/**
 * print_diagonal - draws a diagonal line
 * @n: number of backslashes to print
 */
void print_diagonal(int n)
{
	int line;
	int space;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	line = 0;
	while (line < n)
	{
		space = 0;
		while (space < line)
		{
			_putchar(' ');
			space++;
		}
		_putchar('\\');
		_putchar('\n');
		line++;
	}
}
