#include <stdio.h>

/**
 * main - print alpabet
 * alphabet: tht char who be print
 * Return: Always 0 (Success)
 */

int main(void)
{
int alphabet = 0;
char blphabet;

for (alphabet = 0; alphabet <= 9; alphabet++)
{
putchar('0' + alphabet);
}

for (blphabet = 'a'; blphabet <= 'f'; blphabet++)
{
putchar(blphabet);
}

putchar('\n');
return (0);
}
