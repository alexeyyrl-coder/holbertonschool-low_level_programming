#include "dog.h"
#include <stdlib.h>

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
	 	dog->name[i] = source[i];
		printf("d");
		d++;
	}
	dog->name[i] = '\0';
	
	i = 0;
	while (name[i] != '\0' )
	{
		dog->name[i] = name[i];
		i++;
	}

	dog->age = age;

	return (dog);
}
