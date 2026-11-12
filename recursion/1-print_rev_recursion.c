#include "main.h"

/**
* _print_rev_recursion - Entry point of the program
* @s: - est un pointeur
* Return: Always 0 (Success)
*/

void _print_rev_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}

	s++;
	_putchar(*s);

	_puts_recursion(s);
}
