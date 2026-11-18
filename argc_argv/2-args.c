#include <stdio.h>

/**
 * main - Checks if a character is lowercase
 * @argc: Character to check
 * @argv: est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
