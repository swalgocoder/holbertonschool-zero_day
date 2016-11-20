#include "variadic_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "holberton.h"
#include<stdarg.h>						
 
int _printf(const char *format, ...);				//Our printf function
char* convert(unsigned int, int); 		//Convert integer number into octal, hex, etc.
 
 
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
 
int _printf(const char *format, ...);
{ 
	char *traverse; 
	unsigned int i; 
	char *s; 
	
	//Module 1: Initializing Myprintf's arguments 
	va_list arg; 
	va_start(arg, format); 
	
	for(traverse = format; *traverse != '\0'; traverse++) 
	{ 
		while( *traverse != '%' ) 
		{ 
			putchar(*traverse);
			traverse++; 
		} 
		
		traverse++; 
		
		//Module 2: Fetching and executing arguments
		switch(*traverse) 
		{ 
			case 'c' : i = va_arg(arg,int);		//Fetch char argument
						putchar(i);
						break; 
						
			case 'd' : i = va_arg(arg,int); 		//Fetch Decimal/Integer argument
						if(i<0) 
						{ 
							i = -i;
							putchar('-'); 
						} 
						puts(convert(i,10));
						break; 
						
			case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
						puts(convert(i,8));
						break; 
						
			case 's': s = va_arg(arg,char *); 		//Fetch string
						puts(s); 
						break; 
						
			case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
						puts(convert(i,16));
						break; 
		}	
	} 
	
	//Module 3: Closing argument list to necessary clean-up
	va_end(arg); 
} 
 
char *convert(unsigned int num, int base) 
{ 
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50]; 
	char *ptr; 
	
	ptr = &buffer[49]; 
	*ptr = '\0'; 
	
	do 
	{ 
		*--ptr = Representation[num%base]; 
		num /= base; 
	}while(num != 0); 
	
	return(ptr); 
}


Implementing printf in c
I'm trying to implement printf in c, I have a problem handling some of the conversion, like %S%D%O%U I get Invalid conversion specifier warning, when I use printf.I have to manage the following conversions: sSpdDioOuUxXcC and %p doesn't produce the right results.

char *convert(unsigned int num, int base) 
{ 
    static char Representation[]= "0123456789ABCDEF";
    static char buffer[50]; 
    char *ptr; 

    ptr = &buffer[49]; 
   *ptr = '\0'; 

    do 
    { 
        *--ptr = Representation[num%base]; 
        num /= base; 
    }while(num != 0); 
    return(ptr); 
}

void    my_printf(char *format, ...)
{
    char            *traverse;
    va_list         arg;

    va_start(arg, format);
    traverse = format;
    while (*traverse)
    {
        if (*traverse == '%')
        {
            *traverse++;
            if (*traverse == 'd' || *traverse == 'u' || *traverse == 'i' || *traverse == 'U')
                putnbr(va_arg(arg, int));
            else if (*traverse == 'c' || *traverse == '%' || *traverse == 'C')
                putchar(va_arg(arg, int));
            else if (*traverse == 's')
                puts(va_arg(arg, char *));
            else if (*traverse == 'o')
                puts(convert(va_arg(arg, unsigned int), 8));
            else if (*traverse == 'x')
                puts(convert(va_arg(arg, unsigned int), 16));
            else if (*traverse == 'X')
                puts(convert(va_arg(arg, unsigned int), 16));
            else if (*traverse == 'p')
                puts(va_arg(arg, unsigned long));
            *traverse++;
        }
        putchar(*traverse++);
    }
    va_end(arg);
}
Answers
Alastair Brown May 2016 
I think va_arg always returns whatever is passed to its second argument. Try changing

char *convert(unsigned int num, int base)

to

char *convert(unsigned long num, int base)

and changing your

puts(convert(va_arg(arg, ...), ...));

lines to

puts((unsigned long)convert(va_arg(arg, ...), ...));
