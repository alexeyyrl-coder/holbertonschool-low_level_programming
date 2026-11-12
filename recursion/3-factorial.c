#include "main.h"

/**
* factorial - Entry point of the program
* @n: - est un pointeur
* Return: Always 0 (Success)
*/

int factorial(int n)
{
	if (n == 0)
	{
		return (1);
	}
	else if (n < 0)
	{
		return (-1);
	}

	return (factorial(n - 1) * n);
}
