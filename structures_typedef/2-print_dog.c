#include "dog.h"
#include <stdlib.h>
#include <stdio.h>

/**
* init_dog - Entry point of the program
* @d: - est un pointeur
* Return: Always 0 (Success)
*/

void print_dog(struct dog *d)
{
	if (d == NULL)
	{
		return;
	}

	char *nim;
	char *awn;

	nim = d->name;
	awn = d->owner;

	if (d->name == NULL)
	{
		*nim = "(nil)";
	}

	if (d->owner == NULL)
	{
		*awn = "(nil)";
	}

	printf("Name: %s\n", nim);
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", awn);
}
