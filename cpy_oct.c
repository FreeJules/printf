#include "holberton.h"
/**
 * cpy_hex - moves number in hex to buffer at index
 * @list: list of args
 * @buffer: array of chars to copy to
 * @index: index of buffer to start
 * Return: index
 */
int cpy_hex(va_list list, char *buffer, int index)
{
	long int num, tmp;
	char *hex;
	int i;

	num = va_arg(list, long int);
	hex = malloc(sizeof(char) * 9);
	i = 0;
	while (num > 0)
	{
		tmp = num % 16;
		if (tmp < 10)
			hex[i] = num % 16 + '0';
		else
			hex[i] = num % 16 + 87; /* to make it to 'a' */
		num  = num / 16;
		i++;
	}
	for (i = i - 1; i >= 0; i--, index++)
		buffer[index] = hex[i];
	return (index - 1);
}
/**
 * cpy_HEX - moves number in HEX to buffer at index
 * @list: list of args
 * @buffer: array of chars to copy to
 * @index: index of buffer to start
 * Return: index
 */
int cpy_HEX(va_list list, char *buffer, int index)
{
	long int num, tmp;
	char *hex;
	int i;

	num = va_arg(list, long int);
	hex = malloc(sizeof(char) * 9);
	i = 0;
	while (num > 0)
	{
		tmp = num % 16;
		if (tmp < 10)
			hex[i] = num % 16 + '0';
		else
			hex[i] = num % 16 + 55; /* to make it to 'A' */
		num  = num / 16;
		i++;
	}
	for (i = i - 1; i >= 0; i--, index++)
		buffer[index] = hex[i];
	return (index - 1);
}
/**
 * cpy_oct - moves number in octal to buffer at index
 * @list: list of args
 * @buffer: array of chars to copy to
 * @index: index of buffer to start
 * Return: index
 */
int cpy_oct(va_list list, char *buffer, int index)
{
	long int num;
	char *oct;
	int i;

	num = va_arg(list, long int);
	oct = malloc(sizeof(char) * 12);
	i = 0;
	while (num > 0)
	{
		oct[i] = num % 8;
		num  = num / 8;
		i++;
	}
	for (i = i - 1; i >= 0; i--, index++)
		buffer[index] = oct[i] + '0';
	return (index - 1);
}
