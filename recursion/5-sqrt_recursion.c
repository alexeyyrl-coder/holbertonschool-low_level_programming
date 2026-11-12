#include "main.h"

/**
* funky_style - Entry point of the program
* @n: - est un pointeur
* @j: - est un pointeur
* @v: - est un pointeur
* Return: Always 0 (Success)
*/

int funky_style(int j, int v)
{

	if (j * j > v)
	{
		return (-1);
	}

	if (j * j != v)
	{
		return (funky_style((j + 1), v));
	}

	return (j);
}

/**
* _sqrt_recursion - Entry point of the program
* @n: - est un pointeur
* Return: Always 0 (Success)
*/

int _sqrt_recursion(int n)
{
	if (n == 0)
	{
		return (0);
	}
	else if (n < 0)
	{
		return (-1);
	}

	n = funky_style(1, n);

	return (n);
}
