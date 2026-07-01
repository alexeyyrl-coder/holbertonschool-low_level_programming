#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: converted integer
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int result;
	int found;

	i = 0;
	sign = 1;
	result = 0;
	found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}

		if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			result = result * 10 - (s[i] - '0');
		}
		else if (found == 1)
		{
			break;
		}

		i++;
	}

	if (sign > 0)
	{
		result = -result;
	}

	return (result);
}
