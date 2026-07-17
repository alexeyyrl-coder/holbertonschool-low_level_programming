#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int first;
	int second;
	int result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	first = atoi(argv[1]);
	second = atoi(argv[2]);

	result = first * second;

	printf("%d\n", result);

	return (0);
}
