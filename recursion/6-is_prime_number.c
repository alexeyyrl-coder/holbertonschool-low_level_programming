#include "main.h"

/**
 * _prime_helper - Checks if a number is divisible
 * @n: Number to test
 * @i: Current divisor
 *
 * Return: 1 if prime, 0 otherwise
 */
int _prime_helper(int n, int i)
{
	if (i == n)
	{
		return (1);
	}

	if (n % i == 0)
	{
		return (0);
	}
	return (_prime_helper(n, i + 1));

}
/**
 * is_prime_number - Checks if a number is prime
 * @n: Number to test
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	return (_prime_helper(n, 2));
}
