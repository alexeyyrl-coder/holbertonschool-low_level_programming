#include <stdlib.h>
#include "main.h"

/**
 * str_len - returns the length of a string
 * @s: string to check
 *
 * Return: length of the string
 */
static int str_len(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to a new string, or NULL if it fails
 */
char *str_concat(char *s1, char *s2)
{
	char *str;
	int i;
	int j;
	int len1;
	int len2;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len1 = str_len(s1);
	len2 = str_len(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
