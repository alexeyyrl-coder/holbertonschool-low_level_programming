#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Structure representing a dog
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Dog's owner
 */

void init_dog(struct dog *d, char *name, float age, char *owner);

/*
 * void print_dog(struct dog *d);
 * void free_dog(dog_t *d);
 */

struct dog
{
	char *name;
	char *owner;
	float age;

};

#endif
