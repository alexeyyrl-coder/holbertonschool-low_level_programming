#include <stdlib.h>
#include "main.h"

/**
 * free_lines - frees allocated lines of a grid
 * @grid: grid to free
 * @height: number of lines to free
 */
static void free_lines(int **grid, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}

	free(grid);
}

/**
 * fill_line - fills a line with zeros
 * @line: line to fill
 * @width: width of the line
 */
static void fill_line(int *line, int width)
{
	int w;

	w = 0;
	while (w < width)
	{
		line[w] = 0;
		w++;
	}
}

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer to the grid, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int h;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	h = 0;
	while (h < height)
	{
		grid[h] = malloc(sizeof(int) * width);
		if (grid[h] == NULL)
		{
			free_lines(grid, h);
			return (NULL);
		}
		fill_line(grid[h], width);
		h++;
	}

	return (grid);
}
