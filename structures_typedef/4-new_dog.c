#include "dog.h"
#include <stdlib.h>

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
        {
                i++;
        }

	return (i);
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
	int i;

	dog = malloc(sizeof(dog_t));
	if (dog == 0)
	{	
		return (0);
	}

	/* malloc pour dog->name ici */
	dog->name = malloc(sizeof(char) * (_strlen(name) +1));
	if (dog->name == 0)
	{
		free(dog);
		return (0);
	}

	/* malloc pour dog->owner ici */
	dog->owner = malloc(sizeof(char) * (_strlen(owner)+ 1));
	if (dog->owner == 0)
	{
		free(dog->name);
		free(dog);
		return (0);
	}
	
	dog->age = age;
	
	i = 0;
	while (owner[i] != '\0')
	{
	 	dog->owner[i] = owner[i];
		i++;
	}
	dog->owner[i] = '\0';
	
	i = 0;
	while (name[i] != '\0' )
	{
		dog->name[i] = name[i];
		i++;
	}
	dog->name[i] = '\0';

	dog->age = age;

	return (dog);
}
