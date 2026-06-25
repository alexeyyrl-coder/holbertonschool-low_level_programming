#include <stdio.h>

/**
 * main - Prints all single digit numbers of base 10
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num;

	num = '0';
	while (num <= '9')
	{
		putchar(num);
		num++;
	}
	putchar('\n');

	return (0);
}
