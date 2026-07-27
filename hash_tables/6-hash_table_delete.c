#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: pointer to the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int index;
	hash_node_t *current;
	hash_node_t *next_node;

	if (ht == NULL)
		return;

	for (index = 0; index < ht->size; index++)
	{
		current = ht->array[index];

		while (current != NULL)
		{
			next_node = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = next_node;
		}
	}

	free(ht->array);
	free(ht);
}
