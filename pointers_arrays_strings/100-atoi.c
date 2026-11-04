#include "main.h"

/**
* _strlen - Entry point of the program
* @str: - est un pointeur
* Return: Always 0 (Success)
*/

int _atoi(char *s)
{
	int dec = 0;

	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
		{
			dec = dec * 10 + (*s - '0');
		}

		s++;
	}

	return (dec);
}