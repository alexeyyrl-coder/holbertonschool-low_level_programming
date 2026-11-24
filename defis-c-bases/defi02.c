#include <stdio.h>

int main(void)
{
	int i = 0;

	while (i <= 100)
	{
		if (i % 2 == 0)
		{
			printf("%d ", i);
		}
		

		i++;
	}
	
	printf("\n");
	return (0);
}