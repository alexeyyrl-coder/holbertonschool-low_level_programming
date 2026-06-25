#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char a;

	a = 'a';
	while (a <= 'z')
	{
		if(a != 'e' && a != 'q')
		{
		putchar(a);
		}
		a++;
	}
	putchar('\n');

	return (0);
}
