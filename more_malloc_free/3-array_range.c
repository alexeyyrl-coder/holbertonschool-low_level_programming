#include <stdlib.h>
#include "main.h"

/**
 * array_range - Creates an array of integers from min to max
 * @min: Minimum value
 * @max: Maximum value
 *
 * Return: Pointer to the array, or NULL if it fails
 */
int *array_range(int min, int max)
{
	int *array;
	int i;
	int size;

	if (min > max)
	{
		return (0);
	}

	size = max - min + 1;

	array = malloc (sizeof(int) * size);
	if (array == 0)
	{
		return (0);
	}

	i = 0;
	while (i < size)
	{
		array[i] = min + i;
		i++;
	}

	return (array);
}
