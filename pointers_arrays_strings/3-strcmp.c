#include "main.h"

/**
* _strcmp - Entry point of the program
* @s1: - est un pointeur
* @s2: - est un autre pointeur
* Return: Always 0 (Success)
*/

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') ; i++)
	{}
	i = s1[i] - s2[i];

	return (i);
}