#include "lists.h"
#include <string.h>

/**
 * create_node - Creates a new node
 * @str: String to duplicate
 * Return: Address of the new node or NULL
 */
static list_t *create_node(const char *str)
{
	list_t *nod;
	char *stang;
	unsigned int i;

	nod = malloc(sizeof(*nod));
	if (!nod)
		return (NULL);

	stang = strdup(str);
	if (!stang)
	{
		free(nod);
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
		;

	nod->str = stang;
	nod->len = i;
	nod->next = NULL;

	return (nod);
}

/**
 * add_node_end - Adds a node at the end of a list
 * @head: Address of the head pointer
 * @str: String to duplicate
 * Return: Address of the new node or NULL
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *nod;
	list_t *cusor;

	if (!head || !str)
	{
		return (NULL);
	}
	nod = create_node(str);
	if (!nod)
	{
		return (NULL);
	}
	cusor = *head;

	if (*head == NULL)
	{
		*head = nod;
	}
	else
	{
		while (cusor->next != NULL)
		{
			cusor = cusor->next;
		}

		cusor->next = nod;
	}

	return (nod);
}
