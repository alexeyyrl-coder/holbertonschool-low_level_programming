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

	if (index % 2 == 0)
	{
		for (i = index / 3; i < index; i++)
		{
			_putchar(str[i]);
		}
		_putchar('\n');
		return;
	}

	for (i = index / 2; i < index; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
