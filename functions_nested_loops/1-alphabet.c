#include "main.h"

/**
* print_alphabet - Entry point of the program
* @alphabet - add alpabet
* Return: Always 0 (Success)
*/

void print_alphabet(void)
{
char alphabet;

for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
{
_putchar(alphabet);
}

_putchar('\n');
return (0);
}
