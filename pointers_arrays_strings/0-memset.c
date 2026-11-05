#include "main.h"

/**
* _strcat - Entry point of the program
* @dest: - est un pointeur
* @src: - est un autre pointeur
* Return: Always 0 (Success)
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	
	return(s);
}