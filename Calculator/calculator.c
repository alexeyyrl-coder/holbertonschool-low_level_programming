#include <stdio.h>

/**
 * print_menu - prints the calculator menu
 */
void print_menu(void)
{
	printf("Choose your operation:\n");
	printf("1. Addition\n");
	printf("2. Subtraction\n");
	printf("3. Multiplication\n");
	printf("4. Division\n");
	printf("0. Quit\n");
}

int main(void)
{
	int choic;

	choic = -1;
	while (choic != 0)
	{
		print_menu();
		scanf("%d", &choic);
		
		switch (choic)
		{
		case 0:
		printf("Bye\n");
			break;

		default:
		printf("Invalid choice\n");
			break;
		}

	}

	return(0);
}