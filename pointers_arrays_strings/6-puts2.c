#include "main.h"

/**
* puts2 - Entry point of the program
* @str: - est un pointeur
* Return: Always 0 (Success)
*/

void puts2(char *str)
{
	int index = 0;

	while (*str != '\0')
	{
		if (index % 2 == 0)
		{
			_putchar(*str);
		}
		index++;
		str++;
	}

	_putchar('\n');
}
