#include "main.h"

/**
 * _printf - A custom function to replicate "printf" from the standard library
 * @format: the main string that gets printed
 *
 * Return: num of characters printed except the null byte
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	char c;
	char *s;
	va_list args;

	va_start(args, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case '%':
					_putchar('%');
					count++;
					break;
				case 'c':
					c = va_arg(args, int);
					_putchar(c);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					if (!s)
						break;
					while (*s)
					{
						count++;
						_putchar(*s);
						s++;
					}
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					count = count + 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);

	return (count);
}
