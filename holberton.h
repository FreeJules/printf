#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
/* functions in _putchar.c */
int _putchar(char);
int _strlen(char *);
char *_strcpy(char *dest, char *src);
void _strprint(char *str);
/* functions in cpy_string.c */
int cpy_rev(va_list list, char *buffer, int index);
int cpy_char(va_list list, char *buffer, int index);
int cpy_string(va_list list, char *buffer, int index);
int cpy_bin(va_list list, char *buffer, int index);
int cpy_rot13(va_list list, char *buffer, int index);
/* functions in cpy_int.c */
int cpy_int(va_list list, char *buffer, int index);
int cpy_ui(va_list list, char *buffer, int index);
int cpy_HEX(va_list list, char *buffer, int index);
int cpy_hex(va_list list, char *buffer, int index);
int cpy_oct(va_list list, char *buffer, int index);
/* functions in cpy_special.c */
int cpy_special(va_list list, char *buffer, int index);
/* functons in _printf.c */
int _printf(const char *format, ...);
void clear_buffer(char *);
int buffer_full(char *);
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
#endif
