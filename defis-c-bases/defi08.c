#include <stdio.h>

int main(void)
{
	int i;
	int tbl[] = {4, 7, 2, 9, 3};
	int size = sizeof(tbl) / sizeof(tbl[0]);
	int sumsum = 0;
	int moy = 0;

	printf("Valeurs : ");
	for (i = 0; tbl[i] != tbl[size]; i++)
	{
		printf("%d ", tbl[i]);
	}
	printf("\n");

	for (i = 0; i < size; i++)
	{
		sumsum += tbl[i];
	}
	
	moy = sumsum / size;

	printf("Somme : %d\n", sumsum);
	printf("Moyenne : %d\n", moy);

	return (0);
}