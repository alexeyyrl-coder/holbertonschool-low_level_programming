#include "main.h"
#include <stdlib.h>

/**
* create_array - Entry point of the program
* @size: - est un pointeur
* @c: - est un autre pointeur
* Return: Always 0 (Success)
*/

char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

	if (size == 0)
	{
		return (NULL);
	}

	str = malloc(size);

	if (str == NULL)
	{
		return (NULL);
	}


	for (i = 0; i < size; i++)
	{
		str[i] = c;
	}

	return (str);
}
