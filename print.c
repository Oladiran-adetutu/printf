#include "main.h"

/**
 * select - selects the appropriate specifiers
 * @args: arguements
 * @print: the characters printed
 * @format: the format specified
 * Return: characters that are printed
 */

int select(const char *format, va_list args, int print)
{
	switch (*format)
	{
		case 'd':
		case 'i':
			print = printf_integer(args, print);
			break;
		case 'c':
			_putchar(va_arg(args, int));
			print++;
			break;
		case 's':
			print = printf_string(args, print);
			break;
		case '%':
			_putchar('%');
			print++;
			break;
		case 'b':
			print = printf_binary(va_arg(args, unsigned int), print);
			break;
		case 'x':
		case 'X':
			print = _x(va_arg(args, unsigned int), print, (*format == 'X') ? 1 : 0);
			break;
		case 'o':
			print = printf_octal(va_arg(args, unsigned int), print);
			break;
		case 'u':
			print = printf_unsigned(va_arg(args, unsigned int), print);
			break;
		case 'r':
			print = printf_rev(args, print);
			break;
		case 'p':
			print = printf_points(args, print);
			break;
		default:
			break;
	}
	return (printed);
}
