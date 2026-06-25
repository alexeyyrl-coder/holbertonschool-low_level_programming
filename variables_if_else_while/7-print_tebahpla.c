#include <stdio.h>

/**
 * main - Prints all single digit numbers of base 10
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char z;

	z = 'z';
	while (z >= 'a')
	{
		putchar(z);
		z--;
	}
	putchar('\n');

	return (0);
}
