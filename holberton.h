#ifndef HOLBERTON_H
#define HOLBERTON_H
void _putchar(char);
int _strlen(char *);
char *_strcpy(char *dest, char *src);
void _strprint(char *str);
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
#endif
