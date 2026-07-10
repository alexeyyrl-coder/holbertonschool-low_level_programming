#include <stdlib.h>
#include "main.h"

/**
 * free_grid - frees a 2 dimensional grid
 * @grid: grid to free
 * @height: height of the grid
 */
void free_grid(int **grid, int height)
{
	int h;

	if (grid == NULL)
	{
		return;
	}

	h = 0;
	while (h < height)
	{
		free(grid[h]);
		h++;
	}

	free(grid);
}
