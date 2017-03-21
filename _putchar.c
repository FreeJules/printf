#include "holberton.h"
/**
 * _strcpy - copies the string with \0 to the buffer
 * @dest: pointer to dest
 * @src: pointer to string
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
/**
 * _strprint - prints a string
 * @str: pointer to string to print
 * Return: none
 */
void _strprint(char *str)
{
	int i;

	if (*str != '\0')
	{
		i = 0;
		while (*(str + i) != '\0')
		{
			_putchar(*(str + i));
			i++;
		}
	}
}
/**
 * _strlen - returns the lenght of a string
 * @s: pointer to s
 * Return: 0 on success
 */
int _strlen(char *s)
{
	int count = 0;

	if (s != '\0')
	{
		while (*(s + count) != '\0')
			count++;
	}
	return (count);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
