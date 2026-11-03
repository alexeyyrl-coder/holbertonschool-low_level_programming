#include "main.h"

/**
* swap_int - Entry point of the program
* @norman: - est un pointeur
* @jeffray: - un autre pointeur
* Return: Always 0 (Success)
*/

void swap_int(int *norman, int *jeffray)
{
	int temp;
	temp = 0;

	temp = *norman;

	*norman = *jeffray;
	*jeffray = temp;

}
