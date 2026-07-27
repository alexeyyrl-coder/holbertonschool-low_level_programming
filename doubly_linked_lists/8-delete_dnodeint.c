#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes a node at a given index
 * @head: address of the pointer to the first node
 * @index: index of the node to delete
 *
 * Return: 1 on success, or -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int current_index;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;

		if (*head != NULL)
			(*head)->prev = NULL;

		free(current);
		return (1);
	}

	current_index = 0;

	while (current != NULL && current_index < index)
	{
		current = current->next;
		current_index++;
	}

	if (current == NULL)
		return (-1);

	current->prev->next = current->next;

	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);

	return (1);
}
