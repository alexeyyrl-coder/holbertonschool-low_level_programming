#include "main.h"

/**
 * print_square - prints a square
 * @size: size of the square
 */
void print_square(int size)
{
	int line;
	int col;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	line = 0;
	while (line < size)
	{
		col = 0;
		while (col < size)
		{
			_putchar('#');
			col++;
		}
		_putchar('\n');
		line++;
	}
}
