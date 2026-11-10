#include "main.h"
#include <stdlib.h>

/**
* _strlen - Entry point of the program
* @stix: - est un pointeur
* Return: Always 0 (Success)
*/

int _strlen(char *stix)
{
	int count = 0;

	while (*stix != '\0')
	{
		count++;
		stix++;
	}
	return (count);

}

/**
* _strncat - Entry point of the program
* @dest: - est un pointeur
* @src: - est un pointeru
* @n: - number
* Return: Always 0 (Success)
*/

char *_strncat(char *dest, char *src, unsigned int n)
{
	int i;
	unsigned int j;

	for (i = 0; dest[i] != '\0'; i++)
	{}
	for (j = 0; j < n && src[j] != '\0' ; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
* string_nconcat - Entry point of the program
* @s1: - est un pointeur
* @s2: - est un autre pointeur
* @n: - est un int
* Return: Always 0 (Success)
*/

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int i;

	if (s2 == NULL)
	{
		s2 = "";
	}

	if (s1 == NULL)
	{
		s1 = "";
	}

	for (i = 0; i < n && s2[i] != '\0' ; i++)
	{}

	str = malloc(_strlen(s1) + i + 1);
	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; s1[i] != '\0' ; i++)
	{
		str[i] = s1[i];
	}
	str[i] = '\0';


	str = _strncat(str, s2, n);

	return (str);

}
