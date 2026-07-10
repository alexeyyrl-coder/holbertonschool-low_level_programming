#include <stdlib.h>
#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: String to measure
 *
 * Return: Length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * string_nconcat - Concatenates two strings using n bytes of s2
 * @s1: First string
 * @s2: Second string
 * @n: Number of bytes to use from s2
 *
 * Return: Pointer to the new string, or NULL if it fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int i;
	unsigned int j;
	unsigned int len1;
	unsigned int len2;
	unsigned int copy_len;

	if (s1 == 0)
		s1 = "";

	if (s2 == 0)
		s2 = "";

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (n >= len2)
		copy_len = len2;
	else
		copy_len = n;

	str = malloc(sizeof(char) * (len1 + copy_len + 1));
	if (str == 0)
		return (0);

	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}

	j = 0;
	while (j < copy_len)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';

	return (str);
}
