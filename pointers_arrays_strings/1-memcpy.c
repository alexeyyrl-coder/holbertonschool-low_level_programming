#include "main.h"

/**
* _memcpy - Entry point of the program
* @dest: - est un pointeur
* @src: - est un autre pointeur
* @n: - un int
* Return: Always 0 (Success)
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
