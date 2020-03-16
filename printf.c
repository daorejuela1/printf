#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <holberton.h>
/**
 * _printf - printff function
 * @format: format string first printf string
 * Prototype: int _printf(const char *format, ...);
 * Returns: the number of characters printed 
 *(excluding the null byte used to end output to strings)
 * write output to stdout, the standard output stream
 * format is a character string. The format string is
 * composed of zero or more directives.
 * See man 3 printf for more detail. You need to handle
 * the following conversion specifiers:
 * c s %
 **/
int _printf(const char *format, ...);
{
	struktur1 special[] = {
	{"a", _putchar},
	{"b", _putchar},
	{"f", _putchar},
	{"n", _putchar},
	{"r", _putchar},
	{"t", _putchar},
	{"v", _putchar}
	{NULL, NULL}
	};
	struktur2 form[] = {
	{"c", pchar},
	{"s", pstring},
	{"%", pmod},
	{NULL, NULL}
	}
	char *string = format;
	int a, b, c, d, e;
	va_list valist;

	va_start(valist, format);
	for(a = 1; string[a + 1] != '0'; a++)  /*run through whole strukt*/
	{
		if (string[a] == "\\")
		{
			for (b = 0; b < 3; b++)
			{
				if (string[a + 1] == *struktur1[b].sp)
				{
					struktur1[b].f(*struktur1[b].sp)
					a++;
				}
			}
		}	
	}
	va_end(valist);
	return (0);
}