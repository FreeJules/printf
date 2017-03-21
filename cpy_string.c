#include "holberton.h"
/**
 * cpy_string - moves string to buffer
 * @list: list of args
 * @buffer: array of chars to copy to
 * @index: index to start
 * Return: index
 */
int cpy_string(va_list list, char *buffer, int index)
{
	int i;
	char *s;

	s = va_arg(list, char *);
	for (i = 0; s[i] != '\0'; i++, index++)
		buffer[index] = s[i];
	return (index - 1);
}
/**
 * cpy_char - moves char to buffer at index
 * @list: list of args
 * @buffer: array of chars to copy to
 * @index: index of buffer to start
 * Return: index to end
 */
int cpy_char(va_list list, char *buffer, int index)
{
	char s;

	s = va_arg(list, int);
	buffer[index] = s;
	return (index);
}
/**
 * cpy_rev - moves reversed string to buffer at index
 * @list: list of args
 * @buffer: array of chars to copy to
 * @index: index of buffer to start
 * Return: index
 */
int cpy_rev(va_list list, char *buffer, int index)
{
	int i, len;
	char *str;

	str = va_arg(list, char *);
	len  = _strlen(str);
	for (i = len - 1; i >= 0; i--, index++)
		buffer[index] = str[i];
	return (index - 1);
}
/**
 * cpy_bin - moves number to binary and then to buffer at index
 * @list: list of args
 * @buffer: array of chars to copy to
 * @index: index of buffer to start
 * Return: index
 */
int cpy_bin(va_list list, char *buffer, int index)
{
	unsigned int num, i;

	num = va_arg(list, unsigned int);
	for (i = 1 << 31; i > 0; i = i / 2, index++)
	{
		if (num & i)
			buffer[index] = '1';
		else
			buffer[index] = '0';
	}
	return (index - 1);
}
