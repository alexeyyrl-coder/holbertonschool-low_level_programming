#include "dog.h"
#include <stdlib.h>
#include <stdio.h>

/**
* print_dog - Entry point of the program
* @d: - est un pointeur
* Return: Always 0 (Success)
*/

void print_dog(struct dog *d)
{
	char *nim;
	char *awn;

	if (d == NULL)
	{
		return;
	}


	nim = d->name;
	awn = d->owner;

	if (d->name == NULL)
	{
		nim = "(nil)";
	}

	if (d->owner == NULL)
	{
		awn = "(nil)";
	}

	printf("Name: %s\n", nim);
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", awn);
}
