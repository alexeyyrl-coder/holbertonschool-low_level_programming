#include <stdio.h>
#include <stdlib.h>
#include 3-calc.h

/**
 * op_add - adds two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts the second integer from the first
 * @a: first integer
 * @b: second integer
 *
 * Return: difference between a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides the first integer by the second
 * @a: first integer
 * @b: second integer
 *
 * Return: result of a divided by b
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf(Errorn);
		exit(100);
	}

	return (a / b);
}

/**
 * op_mod - calculates the remainder of a division
 * @a: first integer
 * @b: second integer
 *
 * Return: remainder of a divided by b
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf(Errorn);
		exit(100);
	}

	return (a % b);
}
