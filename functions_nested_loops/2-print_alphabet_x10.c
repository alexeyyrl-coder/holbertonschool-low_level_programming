#include "main.h"

/**
 * print_alphabet_x10- Prints the lowercase alphabet
 */

void print_alphabet_x10(void)
{

        char alp;
	int count;

        alp = 'a';
	count = 0;

	while (count <= 9)
	{
        while (alp <= 'z')
        {
                _putchar(alp);
                alp++;
        }
	alp = 'a';
	count++;
	_putchar('\n');
	}
}

