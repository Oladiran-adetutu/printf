#include "main.h"

/**
 * print_unint - substitute %u by argument number
 * @buff_dest: string to change
 * @arg: va_list arg to change
 * @buff_count: index of dst where the u of %u is
 * Return: New index
 */
int print_unint(char *buff_dest, va_list arg, int buff_count)
{
	int tens = 1;
	unsigned int tmp;
	unsigned int num;

	num = va_arg(arg, unsigned int);

	tmp = num;

	while (tmp > 9)
	{
		tens *= 10;
		tmp /= 10;
	}

	tmp = num;
	while (tens > 0)
	{
		buff_dest[buff_count] = ('0' + tmp / tens);
		tmp %= tens;
		tens /= 10;
		buff_count++;
	}

	return (buff_count);
}
