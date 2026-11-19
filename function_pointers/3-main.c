#include "3-calc.h"
#include <string.h>

/**
 * main - Checks if a character is lowercase
 * @argc: Character to check
 * @argv: est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */

int main(int argc, char **argv)
{
	int rez = 0;
	int (*f)(int, int);

		if (argc > 4 || argc < 4)
		{
			printf("Error\n");
			return (98);
		}

		f = get_op_func(argv[2]);
		if (f == NULL)
		{
			printf("Error\n");
			return (99);
		}

		if ((argv[2][0] == '%' || argv[2][0] == '/')
		&& (atoi(argv[3]) == 0))
		{
			printf("Error\n");
			return (100);
		}


	rez = f(atoi(argv[1]), atoi(argv[3]));

	printf("%d\n", rez);
	return (0);
}
