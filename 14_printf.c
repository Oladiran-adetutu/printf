#include <stdarg.h>
#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 *
 * Return: 1 on success, -1 on error.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: The string to be printed
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _printf - produces output according to a format.
 * @format: A string containing zero or more directives
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int print_chars = 0;
	
	char *str;
	int i, j;
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char rot13_lower[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == 'R')
			{
				str = va_arg(args, char *);

				if (!str)
				{
					_puts("(null)");
					print_chars += 6;
					continue;
				}

				for (j = 0; str[j]; j++)
				{
					if ((str[j] >= 'a' && str[j] <= 'z') ||
					    (str[j] >= 'A' && str[j] <= 'Z'))
					{
						if (str[j] >= 'a' && str[j] <= 'z')
							_putchar(rot13_lower[str[j] - 'a']);
						else
							_putchar(rot13[str[j] - 'A']);
						print_chars++;
					}
					else
					{
						_putchar(str[j]);
						print_chars++;
					}
				}

				continue;
			}
			else if (format[i] == '\0')
				return (-1);
		}

		_putchar(format[i]);
		print_chars++;
	}

	va_end(args);

	return (print_chars);
}

