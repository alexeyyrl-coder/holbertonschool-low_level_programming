#include "function_pointers.h"

/**
 * array_iterator - Checks if a character is lowercase
 * @array: Character to check
 * @size: est un pointeur de fonction
 * @action: est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		(*action)(array[i]);
	}


}
