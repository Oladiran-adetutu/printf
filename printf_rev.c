#include "main.h"

/**
 * printf_rev - prints a binary number
 * @args: arguements
 * @printed: the characters to be printed
 * Return: characters printed
 */

int printf_reverse(va_list args, int print)
{
	char *str = va_arg(args, char *);
	int len = 0, i;

	while (str[len])
	{
		len++;
	}

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(str[i]);
		print++;
	}

	return (print);
}
