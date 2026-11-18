#include <stdio.h>
#include <stdlib.h>

/**
 * main - Checks if a character is lowercase
 * @argc: Character to check
 * @argv: est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */

int main(int argc, char *argv[])
{
	int temp = 0;
	int i;
	int j;


	for (i = 1; i < argc; i++)
	{

		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		temp = temp + atoi(argv[i]);

	}

	printf("%d\n", temp);
	return (0);
}
