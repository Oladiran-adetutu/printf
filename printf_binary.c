#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * printf_binary - Prints a number in binary format
 *
 * @num: The number to print
 *
 * Return: The number of characters printed
 */
int printf_binary(unsigned int num)
{
    int print = 0;

    if (num > 1)
        print += printf_binary(num >> 1);
    print += _putchar((num & 1) + '0');

    return (print);
}

/**
 * _printf - Prints output to stdout according to a format
 *
 * @format: The format string to use
 * @...: Variadic arguments for the format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    int print = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            if (*format == 'b')
                print += printf_binary(va_arg(args, unsigned int));
            else if (*format == '\0')
                return (-1);
            else
                print += _putchar('%') + _putchar(*format);
        }
        else
            print += _putchar(*format);

        format++;
    }

    va_end(args);

    return (print);
}
