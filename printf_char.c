#include "main.h"

/**
 * printf_char - prints a binary number
 * @args: arguements to be printed
 * @print: printed characters
 * Return: the characters that are printed
 */

int printf_char(va_list args, int print)
{
	int character = va_arg(args, int);

	_putchar(character);
	return (print + 1);
}
