#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char a;
	char A;

	a = 'a';
	while (a <= 'z')
	{
		putchar(a);
		a++;
	}

	A = 'A';
	while (A <= 'Z')
	{
		putchar(A);
		A++;
	}
	putchar('\n');

	return (0);
}
