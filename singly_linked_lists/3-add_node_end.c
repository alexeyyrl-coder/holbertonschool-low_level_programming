#include "lists.h"

/**
 * strp - Checks if a character is lowercase
 * @stri: est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */

char *strp(const char *stri)
{
	char *stangu;

	stangu = strdup(stri);
	if (!stangu)
	{
		return (NULL);
	}

	return (stangu);
}

/**
 * add_node_end - Checks if a character is lowercase
 * @head: Character to check
 * @str: est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *nod;
	list_t *cusor;
	char *stang;
	int i;

	if (!head || !str)
		return (NULL);

	stang = strp(str);
	if (!stang)
		return (NULL);

	nod = malloc(sizeof(*nod));
	if (!nod)
		free(stang);
		return (NULL);

	for (i = 0; str[i] != '\0' ; i++)
	{}
	nod->len = i;
	cusor = *head;
	nod->str = stang;
	nod->next = NULL;

	if (*head == NULL)
		*head = nod;
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
