#include "main.h"

/**
 * more_numbers - Checks if a character is lowercase
 * c: Character to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */

void more_numbers(void)
{
int c;
int ff;

for (ff = 0; ff < 10; ff++)
{

for (c = 0; c <= 14; c++)
{

if (c >= 10)
{

_putchar('0' + c / 10);

}

_putchar('0' + c % 10);

}

_putchar('\n');
}

return;
}
