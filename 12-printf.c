#include <stdarg.h>
#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...)
{
    va_list arg;
    int print = 0;
    const char *p = format;

    va_start(arg, format);

    while (*p != '\0') {
        if (*p == '%') {
            switch (*(++p)) {
                case 'b': {
                    unsigned int n = va_arg(arg, unsigned int);
                    unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
                    while (mask > 0) {
                        putchar((n & mask) ? '1' : '0');
                        mask >>= 1;
                    }
                    print += sizeof(unsigned int) * 8;
                    break;
                }
                case 'd':
                case 'i': {
                    int n = va_arg(arg, int);
                    print += printf("%d", n);
                    break;
                }
                default:
                    putchar(*p);
                    print++;
                    break;
            }
        } else {
            putchar(*p);
            print++;
        }
        p++;
    }

    va_end(arg);
    return print;
}

