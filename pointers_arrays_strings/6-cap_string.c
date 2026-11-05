#include "main.h"

/**
* cap_string - Entry point of the program
* @str: - est un pointeur
* Return: Always 0 (Success)
*/

char *cap_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((((i == 0) && (str[i] >= 97 && str[i] <= 122))
			|| (str[i] >= 97 && str[i] <= 122))
			&& ((str[i - 1] == ' ' || str[i - 1] == '\t')
			|| (str[i - 1] == '\n' || str[i - 1] == ',')
			|| (str[i - 1] == ';' || str[i - 1] == '.')
			|| (str[i - 1] == '!' || str[i - 1] == '?')
			|| (str[i - 1] == '"' || str[i - 1] == '(')
			|| (str[i - 1] == ')' || str[i - 1] == '{') || str[i - 1] == '}'))

			str[i] = str[i] - 32;
	}

	return (str);
}
