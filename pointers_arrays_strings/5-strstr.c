#include "main.h"
#include <stddef.h>

/**
* _strstr - Entry point of the program
* @haystack: - est un pointeur
* @needle: - est un autre pointeur
* Return: Always 0 (Success)
*/

char *_strstr(char *haystack, char *needle)
{

	int i;
	int j;

	if (needle[0] == '\0')
	{
		return (&haystack[0]);
	}


	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j] || haystack[i + j] == '\0')
			{
				break;
			}
		}

		if (needle[j] == '\0')
		{
			return (&haystack[i]);
		}
	}
	return (NULL);
}
