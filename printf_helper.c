#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "holberton.h"

/**
 * _putchar - put character to stdout
 * @c: character
 *
 * Return: of write
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcat - concatenate two strings
 * @dest: base string
 * @src: string to be added
 *
 * Return: char
 */
char *_strcat(char *dest, char *src)
{
	int i, n;

	i = 0;
	while (dest[i] != '\0')
		i++;
	for (n = 0; src[n] != '\0'; n++)
	{
		dest[i] = src[n];
		i++;
	}
	dest[i] = src[n];
	return (dest);
}

/**
 * print_mychar - print  mychar
 * @ptr_args: ptr to char to print
 * @b: ptr to buffer
 *
 * Return: 1
 */
char *print_mychar(char *base, va_list ptr_args)
{
	char *swap;
	int i;

	swap = malloc(100);
	i = va_arg(ptr_args, int);
	itoa(i, swap);
	_strcat(base, swap);
	free(swap);
	return (base);
}

/**
 * print_mystr - print mystring
 * @b: pointer to buffer
 * @ptr_args: string to print
 *
 * Return: length of str
 */
char *_printstr(char *base, va_list ptr_args)
{
	char *str;

	str = malloc(100);
	*str = va_arg(ptr_args, int);
	_strcat(base, str);
	free(str);
	return (base);
}

/**
 * print_mystring - print mystring
 * @string: string to print
 *
 * Return: 1 or - 1
 */
int print_mystring(char *string)
{
	int i;

	i = 0;
	while (string[i])
	{
		_putchar(string[i]);
		i++;
	}
	_putchar('\0');
	return (1);
}
