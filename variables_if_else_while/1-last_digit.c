#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* more headers goes there */

int last_digit(int ask){

int askus = ask % 10;

if (askus == 0)
{
printf("%d and is 0\n", askus);
}

if (askus > 5)
{
printf("%d and is greater than 5\n", askus);
}

if (askus < 6 && askus != 0)
{
printf("%d and is less than 6 and not 0\n", askus);
}

}

/* betty style doc for function main goes there */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	return (0);
}
