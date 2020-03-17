#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"
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
int _printf(const char *format, ...)
{
	int i = 0;
	char *buffer = malloc(_strlen(format) * sizeof (char));
	while (format[i])
    {
        buffer[i] = format[i];
        i++;
    }
	va_list valist;
	
	va_start(valist, format);
	if (buffer == NULL)
	{
		return (-1);
	}
	if (buffer == "%")
	{
		return (-1);
	}
	for (i = 0; buffer[i] != '0'; i++)
	{
		if (buffer[i] == '%')
		{
			switch(buffer[i + 1])
			{
				case 'c' :
				buffer = save_c(buffer, i, va_arg(valist, int));
				break;
				case 's' :
				buffer = save_s(buffer, i, va_arg(valist, char *));
				break;
				case 'd' :
				buffer = save_d(buffer, i, va_arg(valist, int));
				break;
				case 'i' :
				buffer = save_d(buffer, i, va_arg(valist, int));
				break;
				default:
				break;
			}
		}
	}
	puts(buffer);
	va_end(valist);
	return (buffer);
}