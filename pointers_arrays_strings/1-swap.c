#include "main.h"

/**
* reset_to_98 - Entry point of the program
* @norman: - est un pointeur
* @jeffray: - un autre pointeur
* Return: Always 0 (Success)
*/

void swap_int(int *norman, int *jeffray)
{
	int temp;
	temp = &norman;
	*norman = &jeffray;
	*jeffray = temp;

}