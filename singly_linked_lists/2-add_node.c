#include "lists.h"

/**
 * add_node - Checks if a character is lowercase
 * @head: Character to check
 * @str: est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *nod;
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

	nod->str = stang;
	nod->len = i;
	nod->next = *head;
	*head = nod;

	return (nod);

}
