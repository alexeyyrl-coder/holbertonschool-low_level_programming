#include <stdio.h>

/**
 * main - Checks if a character is lowercase
 * @: Character to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */

int main(void)
{

int dark;

for (dark = 1; dark <= 100; dark++)
{

if (dark % 3 == 0 && dark % 5 == 0)
{
printf("FizzBuzz ");
}

if (dark % 3 == 0)
{
printf("Fizz ");
}

if (dark % 5 == 0)
{
printf("Buzz ");
}

if (dark % 5 != 0 && dark % 3 != 0)
{
printf("%d ", dark);
}
}

printf("\n");

return (0);
}
