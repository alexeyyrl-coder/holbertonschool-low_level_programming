#include "main.h"

/**
 * _isupper - Checks if a character is lowercase
 * @c: Character to check
 *
 * Return: 1 if lowercase, 0 otherwise
 */

int _isupper(int c)
{

if (c <= 90 && c >= 65)
{
return (1);
}

return (0);

}
