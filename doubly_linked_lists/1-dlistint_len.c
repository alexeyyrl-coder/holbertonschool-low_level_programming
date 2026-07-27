#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a doubly linked list
 * @h: pointer to the first node
 *
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t nodes;

	nodes = 0;
	while (h != NULL)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}
