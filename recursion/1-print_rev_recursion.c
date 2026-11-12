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
		return;
	}

	s++;
	_putchar(*s);
	_print_rev_recursion(s);

}
