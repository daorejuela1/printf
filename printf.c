#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"
#include <unistd.h>
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
 * Return: return the string
 **/
int _printf(const char *format, ...)
{
	int i = 0;
	char *buffer = malloc(_strlen((char *)format) * sizeof(char) + 1);
	va_list valist;
	if (format == NULL)
  	return (-1);
	while (format[i])
	{
		buffer[i] = format[i];
		i++;
	}
	va_start(valist, format);
	if (buffer == NULL)
		return (-1);
	if (*buffer == '%' && *(buffer + 1) == 0)
		return (-1);
	for (i = 0; format[i] != '0'; i++)
	{
		if (buffer[i] == '%')
		{
			switch (buffer[i + 1])
			{
				case 'c':
				buffer = save_c(buffer, i - 1, va_arg(valist, int));
				break;
				case 's':
				buffer = save_s(buffer, i - 1, va_arg(valist, char *));
				break;
				case 'd':
				buffer = save_d(buffer, i - 1, va_arg(valist, int));
				break;
				case 'i':
				buffer = save_d(buffer, i - 1, va_arg(valist, int));
				break;
				default:
				break;
			}
		}
	}
	va_end(valist);
	return (write(1, buffer, _strlen(buffer)));
}
