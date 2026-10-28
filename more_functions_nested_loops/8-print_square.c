#include "main.h"

/**
 * print_square - Checks if a character is lowercase
 * @size: Character to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */

void print_square(int size)
{

int i;
int vi;

if (size <= 0)
{
_putchar('\n');
return;
}

for (i = 0; i < size; i++)
{

for (vi = 0; vi < size; vi++)
{
_putchar('#');
}

_putchar('\n');

}

return;

}
