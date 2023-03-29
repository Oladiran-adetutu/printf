#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
/*
 * _printf - prints
 * @format: format
 * args: arguments
 */

int printf(const char *format, ...)
{
    int print = 0;
    va_list args;
    va_start(args, format);
    while (*format) {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                int c = va_arg(args, int);
                putchar(c);
                print++;
            }else if (*format == 's') {
                char *s = va_arg(args, char*);
                fputs(s, stdout);
                print += strlen(s);
            }else if (*format == 'd' || *format == 'i'){
                int num = va_arg(args, int);
                printf("%d", num);
                print += snprintf(NULL, 0, "%d", num);
            }else if (*format == '%'){
                putchar('%');
                print++;
            }
        }else {
            putchar(*format);
            print++;
        }
        format++;
    }
    va_end(args);
    return print;
}

/**
 * printf_char - prints a binary number
 * @args: arguements to be printed
 * @print: printed characters
 * Return: the characters that are printed
 */

int printf_char(va_list args, int print);

int _putchar(char c)
{
    return putchar(c);
}

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
            switch (*format)
            {
                case 'u':
                    print += printf("%u", va_arg(args, unsigned int));
                    break;
                case 'o':
                    print += printf("%o", va_arg(args, unsigned int));
                    break;
                case 'x':
                    print += printf("%x", va_arg(args, unsigned int));
                    break;
                case 'X':
                    print += printf("%X", va_arg(args, unsigned int));
                    break;
                default:
                    print += _putchar('%');
                    print += _putchar(*format);
                    break;
            }
        }
        else
        {
            print += _putchar(*format);
        }
        format++;
    }

    va_end(args);

    return print;
}

