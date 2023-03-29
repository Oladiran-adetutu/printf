#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <string.h>

int _printf(const char *format, ...){
    int print = 0;
    va_list args;
    va_start(args, format);
    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == 'c') {
                int c = va_arg(args, int);
                putchar(c);
                print++;
            } else if (*format == 's') {
                char *s = va_arg(args, char*);
                fputs(s, stdout);
                print += strlen(s);
            } else if (*format == 'd' || *format == 'i') {
                int num = va_arg(args, int);
                printf("%d", num);
                print += snprintf(NULL, 0, "%d", num);
            } else if (*format == 'b') {
                unsigned int num = va_arg(args, unsigned int);
                int binary[32];
                int i = 0;
                while (num > 0) {
                    binary[i] = num % 2;
                    num /= 2;
                    i++;
                }
                if (i == 0) {
                    putchar('0');
                    print++;
                } else {
                    for (int j = i - 1; j >= 0; j--) {
                        putchar(binary[j] + '0');
                        print++;
                    }
                }
            } else if (*format == '%') {
                putchar('%');
                print++;
            }
        } else {
            putchar(*format);
            print++;
        }
        format++;
    }
    va_end(args);
    return print;
}

