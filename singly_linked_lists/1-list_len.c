#include "lists.h"

/**
 * list_len - Checks if a character is lowercase
 * @h: est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */

size_t list_len(const list_t *h)
{
	unsigned int z = 0;

	while (h)
	{
		z++;

		h = h->next;

	}

	return (z);

}
