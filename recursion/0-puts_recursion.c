#include "main.h"

/**
* _puts_recursion - Entry point of the program
* @s: - est un pointeur
* Return: Always 0 (Success)
*/

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		return;
	}

	_puts_recursion(s++);

}
