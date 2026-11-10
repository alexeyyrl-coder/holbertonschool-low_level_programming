#include "main.h"
#include <stdlib.h>

/**
* _calloc - Entry point of the program
* @nmemb: - est un pointeur
* @size: - est un autre pointeur
* Return: Always 0 (Success)
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned char *meheb;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	meheb = malloc(nmemb * size);
	if (meheb == NULL)
	{
		return (NULL);
	}


	for (i = 0; i < nmemb * size; i++)
	{
		meheb[i] = 0;
	}

	return (meheb);
}
