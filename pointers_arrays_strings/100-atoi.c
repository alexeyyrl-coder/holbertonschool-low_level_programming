#include "main.h"
#include <limits.h>

/**
* positive_process - Entry point of the program
* @s: - est un pointeur
* @verf: - acumulator
* Return: Always 0 (Success)
*/

int positive_process(int verf, char *s)
{
	while (*s >= '0' && *s <= '9')
	{
		if (
		(verf > INT_MAX / 10) || (verf == INT_MAX / 10 && (*s - '0') > INT_MAX % 10))
		{
			verf = INT_MAX;
			break;
		}

		verf = verf * 10 + (*s - '0');
		s++;
	}

	return (verf);
}

/**
* negative_process - Entry point of the program
* @s: - est un pointeur
* @verf: - acumulator
* Return: Always 0 (Success)
*/

int negative_process(int verf, char *s)
{
	while (*s >= '0' && *s <= '9')
	{
		if (
		(verf < INT_MIN / 10)
		||
		(verf == INT_MIN / 10 && -(*s - '0') < INT_MIN % 10))
		{
			verf = INT_MIN;
			break;
		}

		verf = verf * 10 - (*s - '0');
		s++;
	}
	return (verf);
}

/**
* _atoi - Entry point of the program
* @s: - est un pointeur
* Return: Always 0 (Success)
*/

int _atoi(char *s)
{
	int selector = 0;
	int dec = 0;

	while (*s != '\0')
	{
		if (*s == '-')
		{
			selector = !selector;
		}
		else if (*s >= '0' && *s <= '9')
		{
			break;
		}

		s++;
	}

	if (selector == 1)
	{
		dec = negative_process(dec, s);
	}
	else
	{
		dec = positive_process(dec, s);
	}

	return (dec);

}
