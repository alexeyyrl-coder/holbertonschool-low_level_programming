#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * create_hash_node - creates a new hash table node
 * @key: key to duplicate
 * @value: value to duplicate
 *
 * Return: pointer to the new node, or NULL on failure
 */
static hash_node_t *create_hash_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	return (node);
}

/**
 * update_hash_value - updates the value of an existing node
 * @node: node to update
 * @value: new value to duplicate
 *
 * Return: 1 on success, or 0 on failure
 */
static int update_hash_value(hash_node_t *node, const char *value)
{
	char *new_value;

	new_value = strdup(value);
	if (new_value == NULL)
		return (0);

	free(node->value);
	node->value = new_value;

	return (1);
}

/**
 * hash_table_set - adds or updates a key/value pair
 * @ht: hash table
 * @key: key to add or update
 * @value: value associated with the key
 *
 * Return: 1 on success, or 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *current;
	hash_node_t *new_node;

	if (ht == NULL || ht->array == NULL || key == NULL || value == NULL)
		return (0);
	if (key[0] == '\0' || ht->size == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (update_hash_value(current, value));
		current = current->next;
	}

	new_node = create_hash_node(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
