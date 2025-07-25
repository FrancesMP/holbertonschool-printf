#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format string.
 * Supports only the %c specifier for now.
 * @format: A string containing zero or more characters and format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */

int _printf(const char *format, ...)

{
	va_list args;
	int i = 0;
	int count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			count += print_char(args);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}

/**
 * _printf - Produces output according to a format string.
 * Supports %s specifier.
 *
 * @format: The format string.
 *
 * Return: Number of characters printed.
 */


{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] == 's')
			{
				count += print_string(args);
				i += 2;
				continue;
			}
		}
		write(1, &format[i], 1);
		count++;
		i++;
	}

	va_end(args);
	return (count);
}

/**
 * _printf - Produces output according to a format string.
 * Supports %% specifier.
 *
 * @format: The format string.
 *
 * Return: Number of characters printed.
 */


{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] == '%')
			{
				count += print_percent(args);
				i += 2;
				continue;
			}
		}
		write(1, &format[i], 1);
		count++;
		i++;
	}

	va_end(args);
	return (count);
}

