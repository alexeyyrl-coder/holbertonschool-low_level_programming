#include "main.h"
#include <stdlib.h>

/**
* array_range - Entry point of the program
* @min: - est un pointeur
* @max: - est un autre pointeur
* Return: Always 0 (Success)
*/

int *array_range(int min, int max)
{
	int *point;
	int i;

	if (min > max)
	{
		return (NULL);
	}

	point = malloc((max - min + 1) * sizeof(int));
	if (point == NULL)
	{
		return (NULL);
	}


	for (i = 0; i <= max - min; i++)
	{
		point[i] = min + i;
	}


	return (point);
}
