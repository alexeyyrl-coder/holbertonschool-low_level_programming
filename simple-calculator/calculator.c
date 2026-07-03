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

/**
 * calculate - calculates the result of an operation
 * @choice: operation choice
 * @a: first number
 * @b: second number
 *
 * Return: result of the operation
 */
int calculate(int choice, int a, int b)
{
	if (choice == 1)
	{
		return (a + b);
	}
	if (choice == 2)
	{
		return (a - b);
	}
	if (choice == 3)
	{
		return (a * b);
	}
	if (choice == 4)
	{
		return (a / b);
	}

	return (0);
}

/**
 * main - runs a simple calculator
 *
 * Return: 0 on success, 1 on input error
 */
int main(void)
{
	int choice;
	int a;
	int b;
	int result;

	choice = -1;
	while (choice != 0)
	{
		print_menu();

		if (scanf("%d", &choice) != 1)
		{
			return (1);
		}

		if (choice == 0)
		{
			printf("Bye!\n");
			return (0);
		}

		if (choice < 1 || choice > 4)
		{
			printf("Invalid choice\n");
			continue;
		}

		printf("Enter first number: ");
		if (scanf("%d", &a) != 1)
		{
			return (1);
		}

		printf("Enter second number: ");
		if (scanf("%d", &b) != 1)
		{
			return (1);
		}

		if (choice == 4 && b == 0)
		{
			printf("Cannot divide by zero\n");
			continue;
		}

		result = calculate(choice, a, b);
		printf("Result: %d\n", result);
	}

	return (0);
}
