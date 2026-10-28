#include "main.h"

/**
 * print_diagonal - Checks if a character is lowercase
 * @zizi: Character to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */

void print_diagonal(int zizi)
{
int cout;
int i;

if (zizi >= 0)
{
_putchar('\n');
return;
}


for (cout = 0; cout < zizi; cout++)
{

for (i = 0; i < cout; i++)
{
_putchar(' ');
}


if (zizi != 0)
{
_putchar('\\');
}

_putchar('\n');
}

return (0);
}
