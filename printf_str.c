#include "main.h"

/**
 * printf_string - prints a string
 * @args: arguements
 * @print: characters printed
 * Return: characters to be printed
 */

int printf_str(va_list args, int print)
{
	char *str = va_arg(args, char *);

	while (*str != '\0')
	{
		_putchar(*str);
		print++;
		string++;
	}
	return (print);
}
