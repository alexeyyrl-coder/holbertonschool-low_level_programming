#include <stdio.h>

int main(void)
{
	int i;
	int j;
	int k = 1;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < k; j++)
		{
			printf("*");
		}
		printf("\n");
		k++;
	}

	return (0);
}