#include "main.h"

/**
* _strncat - Entry point of the program
* @dest: - est un pointeur
* @src: - est un pointeru
* @n: - number
* Return: Always 0 (Success)
*/

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
	{}
	for (j = 0; j < n && src[j] != '\0' ; j++)
	{
		dest[i] = src[j];
		i++;
	}

	return (dest);
}
