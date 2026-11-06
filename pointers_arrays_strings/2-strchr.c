#include "main.h"
#include <stddef.h>

/**
* _strchr - Entry point of the program
* @s: - est un pointeur
* @c: - est un autre pointeur
* Return: Always 0 (Success)
*/

char *_strchr(char *s, char c)
{
	int i;

	if (s == NULL)
	{
		return (NULL);
	}

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}

	}

	if (c == '\0')
	{
		return (&s[i]);
	}
	
	return (NULL);
}
