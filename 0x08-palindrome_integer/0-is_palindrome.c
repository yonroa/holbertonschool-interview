#include "palindrome.h"

/**
 * is_palindrome - Checks whether or not a given unsigned
 * integer is a palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long num = n;
	unsigned long rev = 0;
	unsigned long temp;

	while (num)
	{
		temp = num % 10;
		rev = rev * 10 + temp;
		num = num / 10;
	}
	return (n == rev);
}
