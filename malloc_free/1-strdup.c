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
* _strdup - Entry point of the program
* @str: - est un pointeur
* Return: Always 0 (Success)
*/

char *_strdup(char *str)
{
	int i;
	char *s;

	if (str == NULL)
	{
		return (NULL);
	}

	s = malloc(_strlen(str) + 1);

	if (s == NULL)
	{
		return (NULL);
	}


	for (i = 0; i < _strlen(str); i++)
	{
		s[i] = str[i];
	}

	return (s);
}
