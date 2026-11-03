#include "main.h"

/**
* _puts - Entry point of the program
* @str: - est un pointeur
* Return: Always 0 (Success)
*/

void _puts(char *str)
{

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}

	_putchar('\n');
}
