#include "lists.h"

/**
 * print_name - Checks if a character is lowercase
 * @name: Character to check
 * @f: est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *nod;
	list_t *cusor;
	char *stang;
	int i;

	if (!head || !str)
	{
		return (NULL);
	}


	nod = malloc(sizeof(*nod));
	if (!nod)
	{
		return (NULL);
	}

	stang = strdup(str);
	if (!stang)
	{
		free(nod);
		return (NULL);
	}

	for (i = 0; str[i] != '\0' ; i++)
	{}
	nod->len = i;
	cusor = *head;
	nod->str = stang;
	nod->next = NULL;

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
