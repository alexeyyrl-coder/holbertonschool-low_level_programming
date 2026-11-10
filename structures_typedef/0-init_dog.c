#include "dog.h"

/**
* init_dog - Entry point of the program
* @d: - est un pointeur
* @name: - est un pointeur
* @age: - est un pointeur
* @owner: - est un pointeur
* Return: Always 0 (Success)
*/

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->age = age;
	d->name = name;
	d->owner = owner;
}
