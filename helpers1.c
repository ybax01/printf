#include "main.h"


/**
 * handle_char - handles the %c specifier
 * @c: the character to print
 *
 * Return: the number of characters printed
 */
int handle_char(char c)
{
	return (_putchar(c));
}

/**
 * handle_string - handles the %s specifier
 * @s: the string to print
 *
 * Return: the number of characters printed
 */
int handle_string(char *s)
{
	int count = 0;

	if (!s)
		s = "(null)";
	while (*s)
	{
		count += _putchar(*s);
		s++;
	}
	return (count);
}

/**
 * handle_integer - handles the %d and %i specifiers
 * @n: the integer to print
 *
 * Return: the number of characters printed
 */
int handle_integer(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += handle_integer(num / 10);

	count += _putchar((num % 10) + '0');
	return (count);
}

/**
 * handle_binary - handles the %b specifier
 * @n: the unsigned int to convert to binary
 *
 * Return: the number of characters printed
 */
int handle_binary(unsigned int n)
{
	int count = 0;
	unsigned int num = n;
	int binary[32];
	int i = 0;

	if (n == 0)
		return (_putchar('0'));

	while (num > 0)
	{
		binary[i] = num % 2;
		num /= 2;
		i++;
	}

	for (i--; i >= 0; i--)
		count += _putchar(binary[i] + '0');

	return (count);
}



