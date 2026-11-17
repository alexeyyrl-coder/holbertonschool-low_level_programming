#include "function_pointers.h"

/**
 * print_name - Checks if a character is lowercase
 * @name: Character to check
 * @f: est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
	{
		return;
	}

	(*f)(name);

}
