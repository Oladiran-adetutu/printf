#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int _putchar(char character);
int printf_char(va_list args, int print);
int printf_str(va_list args, int print);
int printf_int(va_list args, int print);
int select(const char *format, va_list args, int print);
int printf_binary(unsigned int num, int print);
int _printf(const char *format, ...);
int _q(unsigned int num, int print, int uppercase);
int printf_octal(unsigned int num, int print);
int printf_unsigned(unsigned int num, int print);
int printf_rev(va_list args, int print);
int printf_points(va_list args, int print);

#endif
