#include "main.h"
#include <stdarg.h>

/**
 * _printf - Produces output according to a format string.
 * Supports %c, %s, %, d, and i specifiers.
 * @format: A string containing characters and format specifiers.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count += handle_format(format, args, &i);
		else
		{
			_putchar(format[i]);
			count++;
			i++;
		}
	}

	va_end(args);
	return (count);
}

