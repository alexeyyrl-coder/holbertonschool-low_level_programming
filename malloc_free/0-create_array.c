#include <stdlib.h>
#include "main.h"

/**
 * create_array - Creates an array of chars and initializes it
 * @size: Size of the array
 * @c: Character used to initialize the array
 *
 * Return: Pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (0);

	array = malloc(sizeof(char) * size);
	if (array == 0)
		return (0);

	i = 0;
	while (i < size)
	{
		array[i] = c;
		i++;
	}

	return (array);
}
