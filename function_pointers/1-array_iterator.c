#include "function_pointers.h"

/**
 * array_iterator - executes a function on each array element
 * @array: pointer to the array
 * @size: number of elements in the array
 * @action: pointer to the function to execute
 *
 * Return: Nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;
	
	if (array == NULL)
	{
		return;
	}

	if (action == NULL)
	{
		return;
	}

	i = 0;
	while (i < size)
	{
		action(array[i]);
		i++;
	}
}
