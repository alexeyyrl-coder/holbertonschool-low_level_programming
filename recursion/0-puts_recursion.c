#include "main.h"

/**
* _puts_recursion - Entry point of the program
* @s: - est un pointeur
* Return: Always 0 (Success)
*/

void _puts_recursion(char *s)
{
	if (*s == '\n')
	{
		return;
	}
	
	_putchar(*s);
	s++;

	_puts_recursion(s);

}
