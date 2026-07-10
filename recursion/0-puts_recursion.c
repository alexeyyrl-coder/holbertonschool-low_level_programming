#include "main.h"

/**
 * _puts_recursion - Prints a string followed by a new line
 * @s: String to print
 */
void _puts_recursion(char *s)
{
	_putchar(*s);
	if (*s == '\0')
	{
	_putchar('\n');
        return;
	}
	else
	{
	_puts_recursion(s + 1);
	_putchar(*s);
	}
}
