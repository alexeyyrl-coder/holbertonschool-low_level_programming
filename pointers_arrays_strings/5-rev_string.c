#include "main.h"

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
		swapper(firstime, str);
		firstime++;
		end--;
	}


}
