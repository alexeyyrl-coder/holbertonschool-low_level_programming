#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - frees a doubly linked list
 * @head: pointer to the first node
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *next_node;

	while (head != NULL)
	{
		next_node = head->next;
		free(head);
		head = next_node;
	}
}
