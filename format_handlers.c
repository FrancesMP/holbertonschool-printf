#include "main.h"

/**
 * handle_format - Handles format specifiers and prints output.
 * @format: The format string.
 * @args: The variadic argument list.
 * @i: Pointer to the current index in the format string.
 *
 * Return: Number of characters printed.
 */
int _handle_format(const char *format, va_list args, int *i)
{
	int count = 0;

	if (format[*i + 1] == 'c')
		count += print_char(args);
	else if (format[*i + 1] == 's')
		count += print_string(args);
	else if (format[*i + 1] == '%')
		count += print_percent(args);
	else if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
		count += print_integer(args);
	else
	{
		_putchar(format[*i]);
		_putchar(format[*i + 1]);
		count += 2;
	}

	*i += 2;
	return (count);
}
