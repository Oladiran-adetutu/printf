#include "main.h"
/**
 * print_rev - substitutes %r by putting number argument in reverse
 * @buff_dest: string to be changed
 * @arg: character to be changed
 * @buff_count: index of dest(string) where the c of %c is
 * Return: new index
 */
int print_rev(char *buff_dest, va_list arg, int buff_count)
{
	int i = 0;
	char *str;

	str = va_arg(arg, char *);
	if (str)
	{
		while (str[i] != '\0')
			i++;
		i = i - 1;
		while (i >= 0)
		{
			buff_dest[buff_count] = str[i];
			buff_count++;
			i--;
		}
	}
	return (buff_count);
}
