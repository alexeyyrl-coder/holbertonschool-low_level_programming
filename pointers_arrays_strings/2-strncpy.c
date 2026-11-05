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
	int com = 0;

	for (i = 0; i < n; i++)
	{
		if (com == 0 && src[i] != '\0')
		{
			dest[i] = src[i];
		}
		else
		{
			com = 1;
			dest[i] = '\0';
		}

	}

	return (dest);
}
