#include "main.h"

/**
 * print_last_digit - Checks if a character is lowercase
 * @c: Character to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */

int print_last_digit(int c)
{

c = c % 10;

if (c < 0)
{
c = -c;
}

_putchar('0' + c);
return (c);

}
