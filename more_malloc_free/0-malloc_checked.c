#include "main.h"
#include <stdlib.h>

/**
* malloc_checked - Entry point of the program
* @b: - est un pointeur
* Return: Always 0 (Success)
*/

void *malloc_checked(unsigned int b)
{
	void *looc;

	if (looc == NULL)
	{
		exit(98);
	}

	looc = malloc(sizeof(looc) * b);

	return (looc);

}
