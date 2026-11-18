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
	int mult = 0;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	mult = atoi(argv[1]) * atoi(argv[2]);

	printf("%d\n", mult);

	return (0);

}
