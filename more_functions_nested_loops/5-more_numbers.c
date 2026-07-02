#include "main.h"

/**
 * more_numbers - prints numbers from 0 to 14 ten times
 */
void more_numbers(void)
{
	int line;
	int n;

	line = 0;
	while (line < 10)
	{
		n = 0;
		while (n <= 14)
		{
			if (n >= 10)
			{
				_putchar((n / 10) + '0');
			}
			_putchar((n % 10) + '0');
			n++;
		}
		_putchar('\n');
		line++;
	}
}
