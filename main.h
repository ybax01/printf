#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);

int handle_char(char c);
int handle_string(char *s);
int handle_integer(int n);
int handle_binary(unsigned int n);
int handle_unsigned(unsigned int n);
int handle_octal(unsigned int n);
int handle_hex(unsigned int n, int uppercase);

int handle_format(const char *format, va_list args);

#endif /* MAIN_H */
