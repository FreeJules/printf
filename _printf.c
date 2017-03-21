#include "holberton.h"
/**
 * buffer_full - sets all the chars in buffer to 0
 * @buffer: buffer print and reset
 * Return: index 0
 */
int buffer_full(char *buffer)
{
	_strprint(buffer);
	clear_buffer(buffer);
	return (0);
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
		{'x', cpy_hex},
		{'X', cpy_HEX},
		{'o', cpy_oct},
		{'u', cpy_ui},
		{'r', cpy_rev},
		{'R', cpy_rot13},
		{'b', cpy_bin},
		{'S', cpy_special},
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
