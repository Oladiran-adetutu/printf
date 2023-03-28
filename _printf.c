#include "main.h"

/**
 * _printf - inbuilt printf implements
 * @format: string to format
 * Return: string formatted
 * _putchar - puts character
 */

int _printf(const char *format, ...)
{
	int print = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			print = select(format, args, print);
			format++;
		}
		else
		{
			_putchar(*format);
			print++;
			format++;
		}
	}
	va_end(args);
	return (print);
}
