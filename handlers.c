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
