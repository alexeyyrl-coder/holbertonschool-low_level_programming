#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to reverse
 */
void rev_string(char *s)
{
	int start;
	int end;
	char tmp;

	start = 0;
	end = 0;

	while (s[end] != '\0')
	{
		end++;
	}
	end--;

	while (start < end)
	{
		tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		start++;
		end--;
	}
}
