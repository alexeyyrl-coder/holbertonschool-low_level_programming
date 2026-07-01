#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: string
 * @c: character to find
 *
 * Return: pointer to first occurrence, or 0
 */
char *_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (s + i);
		}
		i++;
	}

	if (c == '\0')
	{
		return (s + i);
	}

	return (0);
}
