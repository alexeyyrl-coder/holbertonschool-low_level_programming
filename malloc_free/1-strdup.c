#include <stdlib.h>
#include "main.h"

/**
 * _strdup - Returns a pointer to a duplicated string
 * @str: String to duplicate
 *
 * Return: Pointer to the duplicated string, or NULL if it fails
 */
char *_strdup(char *str)
{
	int i;
	int len;
	char *dup;

	if (str == 0)
		return (0);

	len = 0;
	while (str[len] != '\0')
		len++;

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == 0)
		return (0);

	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';

	return (dup);
}
