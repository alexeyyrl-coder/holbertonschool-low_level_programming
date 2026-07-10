#include "main.h"

/**
 * _sqrt_helper - Finds the natural square root
 * @n: Number to test
 * @i: Current possible root
 *
 * Return: Natural square root, or -1
 */
int _sqrt_helper(int n, int i)
{
	if (i * i == n)
	{
		return (i);
	}
	if (i * i > n)
	{
		return (-1);
	}
	else
	{
		return (_sqrt_helper(n, i + 1));
	}
}

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: Number to calculate
 *
 * Return: Natural square root of n, or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (_sqrt_helper(i, 1));
	}
}
