#include "main.h"

/**
* verificator - Entry point of the program
* @j: - est un pointeur
* @v: - est un pointeur
* Return: Always 0 (Success)
*/

int verificator(int j, int v)
{
	if (j * j > v)
	{
		return (1);
	}

	if (v % j == 0)
	{
		return (0);
	}

	return (verificator((j + 1), v));
}

/**
* is_prime_number - Entry point of the program
* @n: - est un pointeur
* Return: Always 0 (Success)
*/

int is_prime_number(int n)
{

	if (n <= 1)
	{
		return (0);
	}


	return (verificator(2, n));
}
