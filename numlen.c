#include "shell.h"
/**
 * numlen - computes the number of digits in a number
 * @n: number
 * Return: the number of digits
 */
int numlen(int n)
{
	int len = 0;

	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	do {
		n /= 10;
		len++;
	} while (n > 0);
	return (len);
}
/**
 * revstr - reverse string
 * @str: string to be reversed
 * Return: reversed string
 */
char *revstr(char *str)
{
	int len = _strlen(str);
	int i = 0;
	char *tmp = malloc(len + 1);

	while (i < len)
	{
		*(tmp + i) = *(str + (len - (i + 1)));
		i++;
	}
	*(tmp + i) = '\0';
	free(str);
	return (tmp);
}
/**
 * i_to_str - converts number to string
 * @n: number to convert
 * Return: string form of number
 */
char *i_to_str(int n)
{
	int len = numlen(n);
	int i;
	char *p = malloc(len + 1);

	if (n < 0)
		n *= -1;
	for (i = 0; i < len && n > 0; i++)
	{
		*(p + i) = (n % 10) + '0';
		n /= 10;
	}
	*(p + i) = '\0';

	return (revstr(p));
}

