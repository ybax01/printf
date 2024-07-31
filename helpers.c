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
		return (count);
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




/**
 * handle_unsigned - handles the %u specifier
 * @n: the unsigned int to print
 *
 * Return: the number of characters printed
 */
int handle_unsigned(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += handle_unsigned(n / 10);

	count += _putchar((n % 10) + '0');
	return (count);
}

/**
 * handle_octal - handles the %o specifier
 * @n: the unsigned int to convert to octal
 *
 * Return: the number of characters printed
 */
int handle_octal(unsigned int n)
{
	int count = 0;
	unsigned int num = n;
	int octal[11];
	int i = 0;

	if (n == 0)
		return (_putchar('0'));

	while (num > 0)
	{
		octal[i] = num % 8;
		num /= 8;
		i++;
	}

	for (i--; i >= 0; i--)
		count += _putchar(octal[i] + '0');

	return (count);
}

/**
 * handle_hex - handles the %x and %X specifiers
 * @n: the unsigned int to convert to hexadecimal
 * @uppercase: flag indicating whether to use uppercase letters
 *
 * Return: the number of characters printed
 */
int handle_hex(unsigned int n, int uppercase)
{
	int count = 0;
	unsigned int num = n;
	char hex[16];
	char *digits;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";

	if (n == 0)
		return (_putchar('0'));

	while (num > 0)
	{
		hex[count] = digits[num % 16];
		num /= 16;
		count++;
	}

	for (count--; count >= 0; count--)
		_putchar(hex[count]);

	return (count + 1);
}
