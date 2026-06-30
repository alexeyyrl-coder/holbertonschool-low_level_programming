#include "main.h"

/**
 * print_alphabet_x10 - Prints the lowercase alphabet 10 times
 */
void print_alphabet_x10(void)
{
	char alp;
	int count;

	count = 0;
	while (count <= 9)
	{
		alp = 'a';
		while (alp <= 'z')
		{
			_putchar(alp);
			alp++;
		}
		_putchar('\n');
		count++;
	}
}
