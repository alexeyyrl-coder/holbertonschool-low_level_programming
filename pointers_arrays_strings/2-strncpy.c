#include "main.h"

/**
* _strncpy - Entry point of the program
* @dest: - est un pointeur
* @src: - est un pointeru
* @n: - number
* Return: Always 0 (Success)
*/

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (src[i] != '\0')
		{
			dest[i] = src[i];
		}
		else
		{
			dest[i] = '\0';
		}

	}

	return (dest);
}
