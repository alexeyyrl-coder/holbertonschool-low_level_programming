#include <stdio.h>

int main(void)
{
	unsigned int j[] = {3, 8, 1, 6, 4, 9};

	printf("Le tableau contient %ld éléments.\n", sizeof(j) / sizeof(j[0]));
	return (0);
}