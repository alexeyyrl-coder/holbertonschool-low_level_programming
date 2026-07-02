#include "main.h"

/**
 * print_triangle - prints a triangle
 * @size: size of the triangle
 */
void print_triangle(int size)
{
	int line;
	int space;
	int hash;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	line = 1;
	while (line <= size)
	{
		space = 0;
		while (space < size - line)
		{
			_putchar(' ');
			space++;
		}

		hash = 0;
		while (hash < line)
		{
			_putchar('#');
			hash++;
		}

		_putchar('\n');
		line++;
	}
}
