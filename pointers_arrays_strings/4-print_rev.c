#include "main.h"

/**
* print_rev - Entry point of the program
* @str: - est un pointeur
* Return: Always 0 (Success)
*/

void print_rev(char *str)
{
	char *firstime = str;

	while (*str != '\0')
	{
		str++;
	}

	while (str != firstime)
	{
		str--;
		_putchar(*str);
	}


	_putchar('\n');


}
