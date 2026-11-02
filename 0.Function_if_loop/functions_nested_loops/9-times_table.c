#include "main.h"

/**
 * times_table - Checks if a character is lowercase
 * : Character to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */

void times_table(void)
{

int z;
int x;
int rez;

for (z = 0; z < 10; z++)
{

for (x = 0; x < 10; x++)
{

rez = x * z;

if (rez / 10 > 0)
{
_putchar('0' + rez / 10);
}

else if (rez / 10 == 0 && x != 0)
{
_putchar(' ');
}

_putchar('0' + rez % 10);

if (x < 9)
{
_putchar(',');
_putchar(' ');
}

}

_putchar('\n');

}


return;

}
