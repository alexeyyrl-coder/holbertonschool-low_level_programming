#include "main.h"

/**
* _strdup - Entry point of the program
* @str: - est un pointeur
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