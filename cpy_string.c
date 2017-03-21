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
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++, index++)
	{
		if (index == 1024)
			index = buffer_full(buffer);
		buffer[index] = s[i];
	}
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
	if (s == '\0')
		return (index - 1);
	if (index == 1024)
		index = buffer_full(buffer);
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
	{
		if (index == 1024)
			index = buffer_full(buffer);
		buffer[index] = str[i];
	}
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
	unsigned int num;
	int i;
	char *bin;

	num = va_arg(list, unsigned int);
	bin = malloc(sizeof(char) * 64);
	if (bin == NULL)
		return (index);
	i = 0;
	while (num > 0)
	{
		if (num % 2 == 0)
			bin[i] = '0';
		else
			bin[i] = '1';
		num = num / 2;
		i++;
	}
	bin[i] = '\0';
	for (i = i - 1; i >= 0; i--, index++)
	{
		if (index == 1024)
			index = buffer_full(buffer);
		buffer[index] = bin[i];
	}
	return (index - 1);
}
/**
 * cpy_rot13 - moves string to rot13 and then to buffer at index
 * @list: list of args
 * @buffer: array of chars to copy to
 * @index: index of buffer to start
 * Return: index
 */
int cpy_rot13(va_list list, char *buffer, int index)
{
	char *rot13;
	int i, j;
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char n[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	rot13 = va_arg(list, char *);
	if (rot13 == NULL)
		return (index);
	for (i = 0; rot13[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
			if (rot13[i] == a[j])
			{
				rot13[i] = n[j];
				break;
			}
	}
	for (i = 0; rot13[i] != '\0'; i++, index++)
	{
		if (index == 1024)
			index = buffer_full(buffer);
		buffer[index] = rot13[i];
	}
	return (index - 1);
}
