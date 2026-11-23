#include <stdio.h>

void Carre(void)
{
	int i;
	int j;

	printf("Carré : \n");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void rectengel(void)
{
	int i;
	int j;

	printf("Carré : \n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main(void)
{
	rectengel();
	Carre();

	return (0);
}