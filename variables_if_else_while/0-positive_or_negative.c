#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*
* ask - checks if a number is positive, negative or zero
* @askus: the number to be checked
* Return: Always 0 (Success)
*/

int ask(int askus)
{

if (askus == 0)
{
printf("%d is zero/d", askus);
}

if (askus > 0)
{
printf("%d is positive/d", askus);
}

if (askus < 0)
{
printf("%d is negative/d", askus);
}

return (0);
}

/*
* main - Entry point
*
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
