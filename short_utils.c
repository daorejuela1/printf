#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "holberton.h"
/**
 * useswitch - check for case
 * @buffer: buffer
 * @valist: valist
 * @i: counter
 */
void useswitch(char *buffer, va_list valist, int i)
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
				case '%':
				buffer = save_c(buffer, i - 1, '%');
				break;
				default:
				break;
		}
	}
}

