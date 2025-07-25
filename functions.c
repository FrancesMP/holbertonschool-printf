#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Prints a single character.
 * @args: va_list containing the character to print.
 *
 * Return: Number of characters printed (1).
 */

int print_char(va_list args)

{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string from the argument list.
 * @args: va_list containing the string to print.
 *
 * Return: Number of characters printed.
 */

int print_string(va_list args)

{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (str[count])
	{
		write(1, &str[count], 1);
		count++;

	}
	return (count);
}


/**
 * print_percent - Prints a percent sign.
 * @args: va_list (unused).
 *
 * Return: Number of characters printed (always 1).
 */


int print_percent(va_list args)


{
	(void)args;
	write(1, "%", 1);
	return (1);
}


/**
 * print_integer - Prints an integer to stdout
 * @args: The list of variadic arguments
 *
 * Return: Number of characters printed
 */
int print_integer(va_list args)
{
	int n = va_arg(args, int);
	int num, last_digit, count = 0;
	char c;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		count++;
		n = -n;
	}

	num = n;

	if (num == 0)
	{
		c = '0';
		write(1, &c, 1);
		return (count + 1);
	}

	char buffer[20];
	int i = 0;

	while (num > 0)
	{
		last_digit = num % 10;
		buffer[i++] = '0' + last_digit;
		num /= 10;
	}

	while (i--)
	{
		write(1, &buffer[i], 1);
		count++;
	}

	return (count);
}

