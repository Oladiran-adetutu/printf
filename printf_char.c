#include "main.h"

/**
 * printf_char - prints a binary number
 * @args: arguements to print
 * @printed: characters printed
 * Return: printed charcaters
 */

int printf_char(va_list args, int printed)
{
	int character = va_arg(args, int);

	_putchar(character);
	return (printed + 1);
}
