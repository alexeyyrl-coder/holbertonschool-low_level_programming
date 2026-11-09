#include "main.h"
#include <stdlib.h>

/**
* alloc_grid - Entry point of the program
* @width: - est un pointeur
* @height: - est un autre pointeur
* Return: Always 0 (Success)
*/

int **alloc_grid(int width, int height)
{
	int **adress;

	if (width == NULL || height == NULL)
	{
		return (NULL);
	}

	adress = malloc(height * sizeof(int *));

	return (adress);

}
