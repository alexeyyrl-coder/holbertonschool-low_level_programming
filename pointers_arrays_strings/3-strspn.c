#include "main.h"

/**
* _strspn - Entry point of the program
* @s: - est un pointeur
* @accept: - est un autre pointeur
* Return: Always 0 (Success)
*/

unsigned int _strspn(char *s, char *accept)
{
	int i;
	int j;
	unsigned int count;

	for (i = 0; s[i] != ' '; i++)
	{
		for (j = 0; accept[j] != '\0' ; j++)
		{
			if (s[i] == accept[j])
			{
				count++;
			}

		}

	}

	return (count);
}
