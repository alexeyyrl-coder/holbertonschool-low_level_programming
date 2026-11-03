#include "main.h"

/**
* _strlen - Entry point of the program
* @stix: - est un pointeur
* Return: Always 0 (Success)
*/

int _strlen(char *stix)
{
	int count = 0;

	while (*stix != '\0')
	{
		count++;
		stix++;
	}
	return (count);

}
