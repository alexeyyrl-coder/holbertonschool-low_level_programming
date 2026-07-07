#include <stdlib.h>
#include dog.h

/**
 * _strlen - Returns the length of a string
 * @s: String to measure
 *
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _strdup - Duplicates a string
 * @str: String to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL
 */
char *_strdup(char *str)
{
	char *dup;
	int i;

	dup = malloc(sizeof(char) * (_strlen(str) + 1));
	if (dup == 0)
		return (0);

	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';

	return (dup);
}

/**
 * new_dog - Creates a new dog
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Dog's owner
 *
 * Return: Pointer to the new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(dog_t));
	if (dog == 0)
		return (0);

	dog->name = _strdup(name);
	if (dog->name == 0)
	{
		free(dog);
		return (0);
	}

	dog->owner = _strdup(owner);
	if (dog->owner == 0)
	{
		free(dog->name);
		free(dog);
		return (0);
	}

	dog->age = age;

	return (dog);
}
