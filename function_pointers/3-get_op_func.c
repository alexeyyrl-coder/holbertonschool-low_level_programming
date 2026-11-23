#include "3-calc.h"
#include <string.h>

/**
 * get_op_func - Checks if a character is lowercase
 * @s: Character to check
 * : est un pointeur de fonction
 * Return: 1 if lowercase, 0 otherwise
 */

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op != NULL && s != NULL)
	{


		if (strcmp(s, ops[i].op) == 0)
		{
			return (ops[i].f);
		}

		i++;
	}

	return (NULL);
}
