#include "lists.h"

/**
 * get_dnodeint_at_index - returns the node at a given index
 * @head: pointer to the first node
 * @index: index of the node, starting from 0
 *
 * Return: address of the requested node, or NULL if it does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int current_index;

	current_index = 0;
	while (head != NULL && current_index < index)
	{
		head = head->next;
		current_index++;
	}

	return (head);
}
