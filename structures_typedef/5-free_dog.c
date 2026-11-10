#include "dog.h"
#include <stdlib.h>
#include <stdio.h>

/**
* free_dog - Entry point of the program
* @d: - est un pointeur
* Return: Always 0 (Success)
*/

void free_dog(dog_t *d)
{
	if (d == NULL)
	{
		return;
	}

	free(d->name);
	free(d->owner);
	free(d);

}
