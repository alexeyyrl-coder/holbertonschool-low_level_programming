#include "main.h"

/**
* print_rev - Entry point of the program
* @str: - est un pointeur
* Return: Always 0 (Success)
*/

void print_rev(char *str)
{
	char firstime = str;

	while (*str != '\0')
	{
		str++;
	}

	while (str != firstime)
	{
		_putchar(*str);
		str--;
	}


	_putchar('\n');


}
