#include <stdio.h>

int main(void)
{
	char amis[] = "Bonjour les amis";
	char voyl[] = "aeiouy";
	int i;
	int j;
	int voy = 0;

	for (i = 0; amis[i] != '\0'; i++)
	{
		for (j = 0; voyl[j] != '\0'; j++)
		{
			if (amis[i] == voyl[j])
			{
				voy++;
			}
			
		}

	}
	
	printf("La chaîne \"%s\" contient %d voyelles.\n", amis, voy);

	return (0);
}