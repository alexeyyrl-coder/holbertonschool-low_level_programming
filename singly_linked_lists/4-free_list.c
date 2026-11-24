#include "lists.h"

/**
 * free_list - Checks if a character is lowercase
 * @head: Character to check
 * Return: 1 if lowercase, 0 otherwise
 */

void free_list(list_t *head)
{
	list_t *cusor;

	while (head)
	{

		cusor = head->next;
		free(head->str);
		free(head);
		head = cusor;

	}

}
