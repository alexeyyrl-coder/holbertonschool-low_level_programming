#include "main.h"

/**
* _pow_recursion - Entry point of the program
* @x: - est un pointeur
* @y: - est un pointeur
* Return: Always 0 (Success)
*/

int _pow_recursion(int x, int y)
{

	if (y < 0)
	{
		return (-1);
	}

	if (y == 0)
	{
		return (1);
	}

	return (_pow_recursion(x, y - 1) * x);
}
