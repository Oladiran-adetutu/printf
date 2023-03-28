#include "main.h"
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _putchar - prints/writes character
 * @character: The character to print
 * Return: 1, success, -1 error
 */

int _putchar(char character)
{
	return (write(1, &character, 1));
}
