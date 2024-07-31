#include "main.h"

/**
 * handle_format - handles the format specifiers
 * @format: the format string
 * @args: the arguments list
 *
 * Return: the number of characters printed
 */
int handle_format(const char *format, va_list args)
{
	int i = 0, count = 0;
	char c, *s;
	int d;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(args, int);
					count += handle_char(c);
					break;
				case 's':
					s = va_arg(args, char *);
					count += handle_string(s);
					break;
				case 'd':
				case 'i':
					d = va_arg(args, int);
					count += handle_integer(d);
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(format[i]);
					break;
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}
	return (count);
}

/**
 * _printf - a replica of "printf" from the standard C library
 * @format: string with possible directives
 *
 * Return: num of characters printed excluding null byte
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	if (!format)
		return (-1);
	count = handle_format(format, args);
	va_end(args);
	return (count);
}

