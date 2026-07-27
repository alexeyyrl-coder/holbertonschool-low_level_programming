#include "lists.h"

/**
 * sum_dlistint - returns the sum of all data in a doubly linked list
 * @head: pointer to the first node
 *
 * Return: sum of all values, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	sum = 0;
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
