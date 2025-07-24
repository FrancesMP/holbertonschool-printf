#include <unistd.h>
#include <stdarg.h>
#include "main.h" 

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings). Returns -1 on error.
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list list_args;
	char num_buffer[20]; /* Buffer for number to string conversion */

	if (format == NULL)
	{
		return (-1);
	}

	va_start(list_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			my_putchar(*format);    /*write(1,format,1)*/
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				va_end(list_args);
				return (-1);
			}
			if (*format == '%')
			{
				my_putchar(*format);
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list_args, int);
				my_putchar(c);                                 /*write(1, &c, 1);*/
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list_args, char *);
				int i = 0;

				if (str == NULL)
				{
					str = "(null)";
				}

				while (str[i] != '\0')
				{
					my_putchar(str[i]);                                          /* write(1, str, str_len); */
				    count ++;
                    i++;
				}

				
			}
			else if (*format == 'd' || *format == 'i')
			{
				long temp_value; /* Use long to handle INT_MIN correctly */
				int value = va_arg(list_args, int);
				char *ptr = num_buffer;
				char *start_ptr;
				char *end_ptr;
				int is_negative = 0; /* Flag for negative numbers */
				int size = 0;

				if (value == 0)
				{
					*ptr++ = '0';
				}
				else
				{
					if (value < 0)
					{
						is_negative = 1;
						temp_value = -(long)value; /* Convert to positive long */
					}
					else
					{
						temp_value = value;
					}

					start_ptr = ptr;

					while (temp_value > 0)
					{
						*ptr++ = (temp_value % 10) + '0';
						temp_value /= 10;
					}

					end_ptr = ptr - 1;

					/* Reverse the digits in the buffer */
					while (start_ptr < end_ptr)
					{
						char temp_char = *start_ptr;
						*start_ptr = *end_ptr;
						*end_ptr = temp_char;
						start_ptr++;
						end_ptr--;
					}

					if (is_negative) /* Add '-' sign if original number was negative */
					{
						/*
						 * This loop shifts all digits to the right
						 * to make space for the '-' at the beginning.
						 */
						char *current = ptr;
						while (current >= num_buffer)
						{
							*(current + 1) = *current;
							current--;
						}
						*num_buffer = '-'; /* Place '-' at the very beginning */
						ptr++; /* Adjust ptr to point past the new first char */
					}
				}
				*ptr = '\0'; /* Null-terminate the string */

				for (size = 0; num_buffer[size] != '\0'; size++)
				{
				my_putchar(num_buffer[size]);            /* write(1, num_buffer, size) */
				count ++;
				}	
			}
		}
		format++;
	}

	va_end(list_args);
	return (count);
}
