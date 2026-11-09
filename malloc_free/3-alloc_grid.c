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
	int i;

	if (width == 0 || height == 0)
	{
		return (NULL);
	}

	adress = malloc(height * sizeof(int *));

	for (i = 0; i < height; i++)
	{
		adress[i] = malloc(width * sizeof(int));
	}


	return (adress);

}
