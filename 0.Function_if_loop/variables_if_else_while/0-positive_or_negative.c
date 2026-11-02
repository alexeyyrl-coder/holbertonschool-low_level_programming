#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
* ask - checks if a number is positive, negative or zero
* @askus: the number to be checked
* Return: Always 0 (Success)
*/
int ask(int askus)
{

if (askus == 0)
{
printf("%d is zero\n", askus);
}

if (askus > 0)
{
printf("%d is positive\n", askus);
}

if (askus < 0)
{
printf("%d is negative\n", askus);
}

return (0);
}

/**
* main - generates a random number and checks if it is positive.
* negative or zero
* Return: Always 0 (Success)
*/

int main(void)
{
int n;

srand(time(0));
n = rand() - RAND_MAX / 2;
ask(n);
return (0);
}
