#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - Checks if a character is lowercase
 * @n: Character to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */

void print_to_98(int n)
{

if (n == 98)
{
printf("%d\n", n);
return;
}


while (n <= 98)
{

if (n == 98)
{
printf("%d\n", n);
break;
}
printf("%d, ", n);
n++;

}

while (n >= 98)
{

if (n == 98)
{
printf("%d\n", n);
break;
}

printf("%d, ", n);
n--;
}

return;
}
