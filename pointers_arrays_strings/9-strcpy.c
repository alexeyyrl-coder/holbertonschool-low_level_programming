#include "main.h"

/**
* _strcpy - Entry point of the program
* @src: - est un pointeur
* @dest: - est un pointeur
* Return: Always 0 (Success)
*/

char *_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}

	return (*dest);
}
