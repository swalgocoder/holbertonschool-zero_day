#include "variadic_functions.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *print_string - a string
 *@ptr_arg1: ptr to arg1
 *@separator: separator
 */
void print_string(va_list ptr_arg1, char *separator)
{
	char *swap_str;

	swap_str = va_arg(ptr_arg1, char *);
	
	if (swap_str == NULL)
	{
		swap_str = "(nil)";
	}
	printf("%s%s", separator, swap_str);
}
/**
 *print_int - an int
 *@ptr_arg1: ptr to arg1
 *@separator: a separator
 */
void print_int(va_list ptr_arg1, char *separator)
{
	printf("%s%d", separator, va_arg(ptr_arg1, int));
}
/**
 *print_float - a float
 *@ptr_arg1: ptr to arg1
 *@separator: a separator
 */
void print_float(va_list ptr_arg1, char *separator)
{
	printf("%s%f", separator, va_arg(ptr_arg1, double));
}
/**
 *print_char -  a character
 *@ptr: ptr to arg1
 *@separator: a separator
 */
void print_char(va_list ptr_arg1, char *separator)
{
	printf("%s%c", separator, va_arg(ptr_arg1, int));
}
/**
 *print_all - all
 *@format: a string
 */
void print_all(const char * const format, ...)
{
	print_arg_t print_arg[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string}
	};
	va_list ptr_arg1;
	unsigned int i, j;
	char *separator;

	va_start(ptr_arg1, format);
	i = 0;
	separator = "";
	while (format != NULL && format[i] != '\0')
	{
		j = 0;
		while (j < 4)
		{
			if (*print_arg[j].c == format[i])
			{
				print_arg[j].f(ptr_arg1, separator);
				separator = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(ptr_arg1);
}
