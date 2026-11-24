#include "lists.h"

/**
 * print_list - Checks if a character is lowercase
 * @h: Character to check
 * Return: 1 if lowercase, 0 otherwise
 */

size_t print_list(const list_t *h)
{
	unsigned int z = 0;

	while (h)
	{

		if (!h->str)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}

		z++;

		h = h->next;

	}

	return (z);

}
