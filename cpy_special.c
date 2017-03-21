#include "holberton.h"
/**
 * cpy_special - moves string to buffer
 * @list: list of args
 * @buffer: array of chars to copy to
 * @index: index to start
 * Return: index
 */
int cpy_special(va_list list, char *buffer, int index)
{
	int i, value1, value2;
	char *str;

	str = va_arg(list, char *);
	for (i = 0; str[i] != '\0'; i++, index++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			if (index == 1024)
				index = buffer_full(buffer);
			buffer[index++] = '\\';
			if (index == 1024)
				index = buffer_full(buffer);
			buffer[index++] = 'x';
			value1 = str[i] / 0x10;
			value2 = str[i] % 0x10;
			if (index == 1024)
				index = buffer_full(buffer);
			if (value1 < 10)
				buffer[index++] = value1 + '0';
			else
				buffer[index++] = (value1 - 10) + 'A';
			if (index == 1024)
				index = buffer_full(buffer);
			if (value2 < 10)
				buffer[index++] = value2 + '0';
			else
				buffer[index++] = (value2 - 10) + 'A';
			index--;
		}
		else
		{
			if (index == 1024)
				index = buffer_full(buffer);
			buffer[index] = str[i];
		}
	}
	return (index - 1);
}
