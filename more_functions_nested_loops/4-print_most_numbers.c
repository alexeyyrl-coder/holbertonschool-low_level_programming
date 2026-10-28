#include "main.h"

/**
 * print_most_numbers - Checks if a character is lowercase
 * c: Character to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */

void print_most_numbers(void)
{
char alphabet;

for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
{
_putchar(alphabet);
}

_putchar('\n');
return;
}
