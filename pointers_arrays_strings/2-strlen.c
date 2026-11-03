#include "main.h"

/**
* _strlen - Entry point of the program
* @stix: - est un pointeur
* Return: Always 0 (Success)
*/

int _strlen(char *stix)
{
	int count;

	while (*stix != "\n")
	{
		count++;
		*stix++;
	}

}
