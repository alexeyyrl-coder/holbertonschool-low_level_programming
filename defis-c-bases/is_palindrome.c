#include <stdio.h>
#include <string.h>

void is_palindrome(const char chaine[])
{
	int i;
	int j;
	int pal = 0;
	int revers = strlen(chaine);
	
	for (i = revers - 1; i >= 0; i--)
	{
		if (chaine[i] != chaine[j])
		{
			pal = 1;
		}
		j++;
	}

	if (pal == 0)
	{
		printf("%s est un palindrome.\n", chaine);
	}
	else
	{
		printf("%s n'est pas un palindrome.\n", chaine);
	}

}