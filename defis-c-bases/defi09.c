#include <stdio.h>

int main(void)
{
	int i;
	int j;
	int sumsum = 0;
	int valeurs[2][3] = {{1, 2, 3}, {4, 5, 6}};
	int sizeX = sizeof(valeurs) / sizeof(valeurs[0]);
	int sizeY = sizeof(valeurs[0]) / sizeof(valeurs[0][0]);
	
	for (i = 0; valeurs[i] != valeurs[sizeX]; i++)
	{
		for (j = 0; valeurs[j] != valeurs[sizeY]; j++)
		{
			printf("%d ", valeurs[i][j]);
		}
		printf("\n");
	}

	for (i = 0; valeurs[i] != valeurs[sizeX]; i++)
	{
		for (j = 0; valeurs[j] != valeurs[sizeY]; j++)
		{
			sumsum += valeurs[i][j];
		}
		
	}
	
	printf("Somme : %d\n", sumsum);

	return (0);
}