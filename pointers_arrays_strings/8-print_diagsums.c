#include "main.h"
#include <stdio.h>

/**
* print_diagsums - Entry point of the program
* @a: - est un pointeur
* @size: - est un autre pointeur
* Return: Always 0 (Success)
*/

void print_diagsums(int *a, int size)
{
	int i;
	int j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			_putchar(a[i * size + j]);
		}

		_putchar('\n');
	}
}
