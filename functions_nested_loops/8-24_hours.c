#include "main.h"

/**
 * jack_bauer - Checks if a character is lowercase
 * h: Character to check
 * m: Character to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */

void jack_bauer(void)
{
int h;
int m;

for (h  = 0; h <= 23; h++)
{

for (m = 0; m <= 59; m++)
{
_putchar('0' + h / 10);
_putchar('0' + h % 10);
_putchar(':');
_putchar('0' + m / 10);
_putchar('0' + m % 10);
_putchar('\n');
}

}

return;

}
