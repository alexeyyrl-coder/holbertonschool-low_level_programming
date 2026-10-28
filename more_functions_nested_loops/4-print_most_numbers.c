#include "main.h"

/**
 * print_most_numbers - Checks if a character is lowercase
 * c: Character to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */

void print_most_numbers(void)
{
int c;

for (c = 0; c <= 9; c++)
{

if (c != 2 && c != 4)
{
_putchar('0' + c);
}

}

_putchar('\n');
return;
}
