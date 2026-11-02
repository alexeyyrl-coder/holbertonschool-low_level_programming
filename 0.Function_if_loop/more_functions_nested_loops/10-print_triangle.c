#include "main.h"

/**
 * print_triangle - Checks if a character is lowercase
 * @zizi: Character to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */

void print_triangle(int zizi)
{
int cout;
int i;

if (zizi <= 0)
{
_putchar('\n');
return;
}


for (cout = 0; cout < zizi; cout++)
{

for (i = 0; i < zizi - cout - 1; i++)
{
_putchar(' ');
}

for (i = 0; i < cout + 1; i++)
{
_putchar('#');
}

_putchar('\n');
}

return;
}
