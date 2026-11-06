#include "main.h"

/**
* _strcat - Entry point of the program
* @dest: - est un pointeur
* @src: - est un autre pointeur
* Return: Always 0 (Success)
*/
void print_chessboard(char (*a)[8])
{
	int i;
	int j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			_putchar(a[i][j]);
		}

		_putchar('\n');
	}
}