#include <stdio.h>

/**
 * main - print alpabet
 * alphabet: tht char who be print
 * Return: Always 0 (Success)
 */

int main(void)
{
int alphabet = 0;

for (alphabet = 0; alphabet <= 9; alphabet++)
{
putchar('0' + alphabet);
}

putchar('\n');
return (0);
}
