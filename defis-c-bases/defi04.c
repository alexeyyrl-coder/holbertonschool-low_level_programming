#include <stdio.h>

int main(void)
{
	int not = 14;
	char *ment = "";

	if (not < 10 && not >= 0)
	{
		ment = "À retravailler";
	}
	else if (not == 10 || not == 11)
	{
		ment = "Passable";
	}
	else if (not == 12 || not == 13)
	{
		ment = "Assez bien";
	}
	else if (not == 14 || not == 15)
	{
		ment = "Bien";
	}
	else if (not >= 16 && not <= 20)
	{
		ment = "Très bien";
	}	
	else
	{
		ment = "Note invalide";
	}
	
	printf("Note : %d\n", not);

	printf("Appréciation : %s\n", ment);

	return (0);
}