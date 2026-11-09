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
* str_concat - Entry point of the program
* @s1: - est un autre pointeur
* @s2: - int
* Return: Always 0 (Success)
*/

char *str_concat(char *s1, char *s2)
{
	char *str;
	int i;
	int j;

	if (s2 == NULL)
	{
		s2 = "";
	}

	if (s1 == NULL)
	{
		s1 = "";
	}

	str = malloc(_strlen(s1) + _strlen(s2) + 1);

	if (str == NULL)
	{
		return (NULL);
	}


	for (i = 0; s1[i] != '\0'; i++)
	{
		str[i] = s1[i];
	}

	for (j = 0; s2[j] != '\0'; j++)
	{
		str[i] = s2[j];
		i++;
	}

	return (str);

}
