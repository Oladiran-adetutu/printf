#include <stdarg.h>
#include "main.h"
#include <string.h>
#include <stdio.h>

/* _printf - prints
 * @args: arguments
 * @format: format
 * Return: printed characters
 */

int _printf(const char *format, ...)
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
