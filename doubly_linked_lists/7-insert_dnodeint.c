#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node at a given index
 * @h: address of the pointer to the first node
 * @idx: index where the new node must be inserted
 * @n: integer to store in the new node
 *
 * Return: address of the new node, or NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h,
				     unsigned int idx, int n)
{
	dlistint_t *current;
	dlistint_t *new;
	unsigned int index;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	current = *h;
	index = 0;

	while (current != NULL && index < idx - 1)
	{
		current = current->next;
		index++;
	}

	if (current == NULL)
		return (NULL);

	if (current->next == NULL)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = current;
	new->next = current->next;
	current->next->prev = new;
	current->next = new;

	return (new);
}
