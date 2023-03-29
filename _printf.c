#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/**
 * _printf - inbuilt printf implements
 * @format: string to format
 * Return: string formatted
 * putchar - puts character
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
            if (*format == 'c') {
                int c = va_arg(args, int);
                putchar(c);
                print++;
        }
	    else if (*format == 's')
	    {
                char *s = va_arg(args, char*);
                fputs(s, stdout);
                print += strlen(s);
            }
	    
	    else if (*format == '%')
	    {
                putchar('%');
                print++;
            }
        }
	else
	{
            putchar(*format);
            print++;
        }
        format++;
    }
    va_end(args);
    return print;
}

