#include "main.h"

/**
 * print_Rot13 - substitutes %R by argument number in rot13
 * @buff_dest: string to change
 * @arg: va_list char to change
 * @buff_count: index ot dst where the R of %R is
 * Return: New index
 */
int print_Rot13(char *buff_dest, va_list arg, int buff_count)
{
	char *str;
	char *keys = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *keynew = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i, j = 0;

	str = va_arg(arg, char *);
	while (str[j])
	{
		for (i = 0; keys[i]; i++)
		{
			if (str[j] == keys[i])
			{
				buff_dest[buff_count] = keynew[i];
				break;
			}
			buff_dest[buff_count] = str[j];
		}
		j++, buff_count++;
	}
	return (buff_count);
}

