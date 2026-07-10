#include <stdlib.h>
#include "main.h"

/**
 * _set_zero - Sets memory bytes to zero
 * @bytes: Pointer to memory
 * @total: Number of bytes to set
 */
void _set_zero(char *bytes, unsigned int total)
{
	unsigned int i;

	i = 0;
	while (i < total)
	{
		bytes[i] = 0;
		i++;
	}
}

/**
 * _calloc - Allocates memory for an array and initializes it to zero
 * @nmemb: Number of elements
 * @size: Size of each element
 *
 * Return: Pointer to the allocated memory, or NULL if it fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int total;

	if (nmemb == 0)
	{
		return (0);
	}

	if (size == 0)
	{
		return (0);
	}

	total = nmemb * size;
	ptr = malloc(total);
	if (ptr == 0)
	{
		return (0);
	}

	_set_zero(ptr, total);

	return (ptr);
}
