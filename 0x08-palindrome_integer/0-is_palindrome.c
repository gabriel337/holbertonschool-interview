#include "palindrome.h"

/**
 * is_palindrome - Checks if number is a palindrome or nor
 * @n: number to be checked
 * Return: 1 if a palindrome, 0 if not.
 */

int is_palindrome(unsigned long n)
{
    unsigned long rev = 0, remainder, OG;

    OG = n;

    while (n != 0)
    {
        remainder = n % 10;
        rev = rev * 10 + remainder;
        n /= 10;
    }

    if (OG == rev)
        return (1);

    return (0);
}