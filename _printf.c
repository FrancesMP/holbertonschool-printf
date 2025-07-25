#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 *_printf - Produces output according to a format string.
 *Supports %c, %s, and %% specifiers.
 *@format: A string containing zero or more characters and format specifiers.
 *
 *Return: The number of characters printed (excluding the null byte).
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
		{
			switch (format[i + 1])
			{
				case 'c':
					count += print_char(args);
					i += 2;
					continue;
				case 's':
					count += print_string(args);
					i += 2;
					continue;
				case '%':
					count += print_percent(args);
					i += 2;
					continue;
				default:
					write(1, &format[i], 1);
					write(1, &format[i + 1], 1);
					count += 2;
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


