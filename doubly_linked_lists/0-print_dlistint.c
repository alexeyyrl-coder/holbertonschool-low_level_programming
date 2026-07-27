#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - prints all elements of a doubly linked list
 * @h: pointer to the first node
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t nodes;

	nodes = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		nodes++;
		h = h->next;
	}

	return (nodes);
}
