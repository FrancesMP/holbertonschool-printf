#include "main.h" 

/**
 * _handle_format - Handles format specifiers and prints output.
 * @format: The format string.
 * @args: The variadic argument list.
 * @i: Pointer to the current index in the format string.
 *
 * Return: Number of characters printed.
 */
int _handle_format(const char *format, va_list args, int *i)
{
	int count = 0;
	char specifier = format[*i + 1];

	if (specifier == 'c')
	{
		count += print_char(args);
	}
	else if (specifier == 's')
	{
		count += print_string(args);
	}
	else if (specifier == '%')
	{
		count += print_percent(args);
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		count += print_integer(args);
	}
	else 
	{
		_putchar('%');       
		_putchar(specifier); 
		count += 2;
	}

	(*i)++;

	return (count);
}
