#include "main.h"

/**
* _strlen_recursion - Entry point of the program
* @s: - est un pointeur
* Return: Always 0 (Success)
*/

int _strlen_recursion(char *s)
{
	int one = 0;

	if (*s == '\0')
	{
		_putchar(one);
		return;
	}

	_puts_recursion(s + 1);
}
