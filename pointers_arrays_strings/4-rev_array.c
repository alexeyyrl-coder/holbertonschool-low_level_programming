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

	temp = *norman;

	*norman = *jeffray;
	*jeffray = temp;

}

/**
* reset_to_98 - Entry point of the program
* @norman: - est un pointeur
* Return: Always 0 (Success)
*/

void reverse_array(int *a, int n)
{
	int i;
	int end;
	end = n - 1;

    i = 0;
    while (i < n / 2)
    {
		swap_int(&a[i], &a[end]);
	    i++;
		end--;
	}
}
