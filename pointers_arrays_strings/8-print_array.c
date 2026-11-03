#include <stdio.h>
#include "main.h"


/**
* print_array - Entry point of the program
* @a: - est un pointeur
* @n: - est pas un pointeur
* Return: Always 0 (Success)
*/

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[n]);
		n++;
	}

	printf("\n");

}
