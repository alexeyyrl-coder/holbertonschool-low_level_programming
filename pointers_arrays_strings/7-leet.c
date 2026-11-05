#include "main.h"

/**
* leet - Entry point of the program
* @str: - est un pointeur
* Return: Always 0 (Success)
*/

char *leet(char *str)
{
	int i;
	int f;
	char *defs;

	defs = "aeotlAEOTL4307143071";

	for (i = 0; str[i] != '\0' ; i++)
	{
		for (f = 0; defs[f] != '4'; f++)
		{
			if (str[i] == defs[f])
			{
				str[i] = defs[f + 10];
			}

		}

	}

	return (str);
}
