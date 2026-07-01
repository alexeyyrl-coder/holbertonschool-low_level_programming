#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: pointer to str
 */
char *cap_string(char *str)
{
	int i;
	int j;
	int cap;
	char sep[] = " \t\n,;.!?\"(){}";

	i = 0;
	cap = 1;

	while (str[i] != '\0')
	{
		if (cap == 1 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}

		cap = 0;
		j = 0;
		while (sep[j] != '\0')
		{
			if (str[i] == sep[j])
			{
				cap = 1;
			}
			j++;
		}
		i++;
	}

	return (str);
}
