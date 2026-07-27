#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_get - retrieves the value associated with a key
 * @ht: pointer to the hash table
 * @key: key to search for
 *
 * Return: value associated with the key, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	if (ht == NULL || ht->array == NULL || key == NULL)
		return (NULL);

	if (key[0] == '\0' || ht->size == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);

		current = current->next;
	}

	return (NULL);
}
