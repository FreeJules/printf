#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int _putchar(char);
int _strlen(char *);
char *_strcpy(char *dest, char *src);
void _strprint(char *str);
void rev_string(char *s);
int _printf(const char *format, ...);
/**
 * struct format - list of conversion specifiers to arguments
 *
 * @c: The specifier
 * @f: The function associated with printing
 */
typedef struct format
{
	char c;
	int (*f)();
} format_t;
int cpy_HEX(va_list list, char *buffer, int index);
int cpy_hex(va_list list, char *buffer, int index);
int cpy_oct(va_list list, char *buffer, int index);
#endif
