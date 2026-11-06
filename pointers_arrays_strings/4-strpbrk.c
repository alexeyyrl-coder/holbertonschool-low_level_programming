#include "main.h"
#include <stddef.h>

/**
* _strpbrk - Entry point of the program
* @s: - est un pointeur
* @accept: - est un autre pointeur
* Return: Always 0 (Success)
*/

char *_strpbrk(char *s, char *accept)
{
int i;
int j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				return (&s[i]);
			}
		}
	}
	return (NULL);
}
