#include "main.h"

/**
* _strcat - Entry point of the program
* @dest: - est un pointeur
* @src: - est un autre pointeur
* Return: Always 0 (Success)
*/

char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
	{}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	return (dest);
}
