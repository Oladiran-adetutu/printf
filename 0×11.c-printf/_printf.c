#include "main.h"

/**
 * _printf - implementation of the inbult printf
 * @format: the format specifier
 * Return: the formated string
 */

int _printf(const char *format, ...)
{
	int printed = 0;

	va_list argss;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			printed = selector(format, args, printed);
			format++;
		}
		else
		{
			_putchar(*format);
			printed++;
			format++;
		}
	}
	va_end(args);
	return (printed);
}

