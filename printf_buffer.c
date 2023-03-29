#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

/*
 * _putchar - puts character
 * _printf - prints character
 * @c: character
 * Return: printed characters
 */

int select(const char *format, va_list args, int print);
/* @format: format
 * args: arguments
 * print: prints character
 * Return: printed character
 */

int _putchar(char c)
{
    return write(1, &c, 1);
}

int _printf(const char *format, ...)
{
    int print = 0;
    va_list args;
    char buffer[1024];
    int buf_index = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'd':
                case 'i':
                    buf_index += sprintf(buffer + buf_index, "%d", va_arg(args, int));
                    break;
                case 'c':
                    buffer[buf_index++] = va_arg(args, int);
                    break;
                case 's':
                    buf_index += sprintf(buffer + buf_index, "%s", va_arg(args, char *));
                    break;
                case '%':
                    buffer[buf_index++] = '%';
                    break;
                default:
                    _putchar('%');
                    _putchar(*format);
                    buf_index += 2;
                    break;
            }
        }
        else
        {
            buffer[buf_index++] = *format;
        }

        if (buf_index >= sizeof(buffer) - 1)
        {
            print += write(1, buffer, buf_index);
            buf_index = 0;
        }

        format++;
    }

    if (buf_index > 0)
    {
        print += write(1, buffer, buf_index);
    }

    va_end(args);

    return print;
}

