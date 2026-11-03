#include "main.h"

/**
* puts_half - Entry point of the program
* @str: - est un pointeur
* Return: Always 0 (Success)
*/

void puts_half(char *str)
{

	int index = 0;
	int i;

	while (str[index] != '\0')
	{
		index++;
	}

	for (i = index / 2; i < index; i++)
	{
		_putchar(str[i]);
	}


	_putchar('\n');
}
