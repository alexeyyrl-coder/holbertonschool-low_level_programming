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
	int a;
	int b;
	int result;

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

		case 1:
		printf("Enter first number: ");
		scanf("%d", &a);
		printf("Enter secound number: ");
		scanf("%d", &b);
		result = a + b;
		printf("result: %d\n", result);
			break;
		
		case 2:
		printf("Enter first number: ");
		scanf("%d", &a);
		printf("Enter secound number: ");
		scanf("%d", &b);
		result = a - b;
		printf("result: %d\n", result);
			break;
		
		case 3:
		printf("Enter first number: ");
		scanf("%d", &a);
		printf("Enter secound number: ");
		scanf("%d", &b);
		result = a * b;
		printf("result: %d\n", result);
			break;

		case 4:

		default:
		printf("Invalid choice\n");
			break;
		}

	}

	return(0);
}