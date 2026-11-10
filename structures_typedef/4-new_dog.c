#include "dog.h"
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

	s[i] = '\0';

	return (s);
}


/**
* new_dog - Entry point of the program
* @name: - est un pointeur
* @age: - est un pointeur
* @owner: - est un pointeur
* Return: Always 0 (Success)
*/

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *doug;

	doug = malloc(sizeof(dog_t));
	if (doug == NULL)
	{
		return (NULL);
	}

	doug->name = _strdup(name);
	if (doug->name == NULL)
	{
		free(doug);
		return (NULL);
	}

	doug->owner = _strdup(owner);
	if (doug->owner == NULL)
	{
		free(doug->name);
		free(doug);
		return (NULL);
	}

	doug->age = age;

	return (doug);

}
