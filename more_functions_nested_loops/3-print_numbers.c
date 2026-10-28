#include "main.h"

/**
 * print_numbers - Checks if a character is lowercase
 * c: Character to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */

void print_numbers(void)
{
int c;

for (c = 0; c <= 9; c++)
{
_putchar('0' + c);
}

_putchar('\n');
return;
}
