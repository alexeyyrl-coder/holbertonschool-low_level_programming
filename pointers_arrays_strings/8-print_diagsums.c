#include "main.h"

/**
* print_number - Entry point of the program
* @n: - est un pointeur
* Return: Always 0 (Success)
*/

void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
	}

	if (n >= 10)
	{
		print_number(n / 10);
	}

	_putchar((n % 10) + '0');
}

/**
* print_diagsums - Entry point of the program
* @a: - est un pointeur
* @size: - est un autre pointeur
* Return: Always 0 (Success)
*/

void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0;
	int sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += (a[i * size + i]);
		sum2 += (a[i * size + (size - 1 - i)]);
	}

	print_number(sum1);
	_putchar(',');
	_putchar(' ');
	print_number(sum2);
	_putchar('\n');
}
