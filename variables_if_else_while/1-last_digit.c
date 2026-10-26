#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * last_digit - checks the last digit of a number
 * @ask: the number to be checked
 * Return: Always 0 (Success)
 */

int last_digit(int ask)
{

int basku = ask;
int askus = ask % 10;

if (askus == 0)
{
printf("Last digit of %d is 0 and is 0\n", basku);
}

if (askus > 5)
{
printf("Last digit of %d is %d and is greater than 5\n", basku, askus);
}

if (askus < 6 && askus != 0)
{
printf("Last digit of %d is %d and is less than 6 and not 0\n", basku, askus);
}
return (0);
}

/**
 * main - generates a random number and checks the last digit
 * Return: Always 0 (Success)
 */


int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	last_digit(n);
	return (0);
}
