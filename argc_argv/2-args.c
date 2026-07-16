#include <stdio.h>

/**
 * main - prints all command-line arguments
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int i;

	i = 0;
	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}

	return (0);
}
