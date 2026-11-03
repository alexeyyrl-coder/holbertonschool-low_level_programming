#include "main.h"

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
