#include "main.h"

/**
 * print_hex - substitutes %x by unsigned int number argument
 * @buff_dest: string to be changed
 * @arg: va_list arg to be changed
 * @buff_count: index of buffer
 * Return: new index
 */
int print_hex(char *buff_dest, va_list arg, int buff_count)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int tmp = num;
	int hex = 1;

	while (tmp > 15)
	{
		hex *= 16;
		tmp /= 16;
	}

	tmp = num;
	while (hex > 0)
	{
		buff_dest[buff_count] = (tmp / hex < 9) ?
			(tmp / hex + '0') : ('a' + tmp / hex - 10);
		tmp %= hex;
		hex /= 16;
		buff_count++;
	}

	return (buff_count);
}

/**
 * print_X - substitutes %X by unsigned int number argument
 * @buff_dest: string to be changed
 * @arg: argument that changes
 * @buff_count: the index of buffer
 * Return: New index
 */
int print_X(char *buff_dest, va_list arg, int buff_count)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int tmp = num;
	int hex = 1;

	while (tmp > 15)
	{
		hex *= 16;
		tmp /= 16;
	}

	tmp = num;
	while (hex > 0)
	{
		buff_dest[buff_count] = (tmp / hex < 9) ?
			(tmp / hex + '0') : ('A' + tmp / hex - 10);
		tmp %= hex;
		hex /= 16;
		buff_count++;
	}

	return (buff_count);
}
