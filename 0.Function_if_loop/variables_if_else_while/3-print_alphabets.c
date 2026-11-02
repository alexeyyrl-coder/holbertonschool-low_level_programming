#include <stdio.h>

/**
 * main - print alpabet
 * alphabet: tht char who be print
 * Return: Always 0 (Success)
 */

int main(void)
{
char alphabet;
char Ulphabet;

for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
{
putchar(alphabet);
}

for (Ulphabet = 'A'; Ulphabet <= 'Z'; Ulphabet++)
{
putchar(Ulphabet);
}

putchar('\n');
return (0);
}
