#include <stdio.h>

/**
 * main - print alpabet
 * alphabet: tht char who be print
 * Return: Always 0 (Success)
 */

int main(void)
{
char alphabet;

for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
{
putchar(alphabet);
}

putchar('\n');
return (0);
}
