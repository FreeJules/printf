#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * cpy_int - moves int to buffer at index
 * @list: list of args
 * @buffer: array of chars to copy to
 * @index: index to start copy
 * Return: index to end + 1
 */
int cpy_int(va_list list, char *buffer, int index)
{
	int div, last_digit, tmp, len;
	int n;

	n = va_arg(list, int);
	/* calcualating last digit */
	last_digit = n % 10;
	/* if negative print '-' and make last digit positive */
	if (last_digit < 0)
	{
		buffer[index] = '-';
		index++;
		last_digit = last_digit * (-1);
	}
	/* calculate the number without the last digit and make positive */
	n = (n / 10);
	if (n < 0)
	{
		n = n * (-1);
	}
	/* calculate the length of a number and div to divide it with */
	len  = 0;
	div = 1;
	tmp = n;
	while (tmp > 0)
	{
		len += 1;
		div *= 10;
		tmp = tmp / 10;
	}
	/* make div one digit shorter than lenght */
	div = div / 10;
	while (div >= 1)
	{
		buffer[index] = n / div + '0';
		n = n % div;
		div /= 10;
		index++;
	}
	buffer[index] = last_digit + '0';
	return (index);
}
/**
 * cpy_string - moves string to buffer
 * @list: list of args
 * @buffer: array of chars to copy to
 * @index: index to start
 * Return: index to end + 1
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
 * Return: index to end + 1
 */
int cpy_char(va_list list, char *buffer, int index)
{
	char s;

	s = va_arg(list, int);
	buffer[index] = s;
	return (index);
}
/**
 * clear_buffer - sets all the chars in buffer to 0
 * @buffer: buffer to reset
 * Return: nothing
 */
void clear_buffer(char *buffer)
{
	int i;

	for (i = 0; i < 1024; i++)
		buffer[i] = 0;
}
/**
 * _printf - function that produces output according to a format (printf)
 * @format: character string composed of zero or more directives
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	format_t specifiers[] = {
		{'c', cpy_char},
		{'s', cpy_string},
		{'d', cpy_int},
		{'i', cpy_int},
		{'\0', NULL}
	};
	char buffer[1024];
	va_list list;
	int i, j, index;

	clear_buffer(buffer);
	va_start(list, format);
	index = 0;
	i = 0;
	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
			buffer[index] = format[i];
		else
		{
			i++;
			j = 0;
			while ((specifiers + j)->c != '\0')
			{
				if (format[i] == (specifiers + j)->c)
					index = (specifiers + j)->f(list, buffer, index);
				j++;
			}
		}
		i++;
		index++;
	}
	va_end(list);
	_strprint(buffer);
	clear_buffer(buffer);
	return (index);
}
