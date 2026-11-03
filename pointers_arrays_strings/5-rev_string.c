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


/**
* swapper - Entry point of the program
* @norman: - est un pointeur
* @jeffray: - un autre pointeur
* Return: Always 0 (Success)
*/

void swapper(char *norman, char *jeffray)
{
	char temp;

	temp = *norman;

	*norman = *jeffray;
	*jeffray = temp;

}

/**
* rev_string - Entry point of the program
* @str: - est un pointeur
* Return: Always 0 (Success)
*/


void rev_string(char *str)
{
	int end = _strlen(str) - 1;
	char *firstime = str;

	while (firstime < &str[end])
	{
		swapper(firstime, &str[end]);
		firstime++;
		end--;
	}


}
