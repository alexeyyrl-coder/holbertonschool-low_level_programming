#include "main.h"
#include <stdlib.h>

/**
* free_grid - Entry point of the program
* @grid: - est un pointeur
* @height: - est un autre pointeur
* Return: Always 0 (Success)
*/

void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
	{
		return;
	}

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
	
}