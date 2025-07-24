#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
/**
* _printf - 
* @format: character string
*
* Return: the number of characters printed or -1 if format is NULL
*/
int _printf(const char *format, ...)
{
int browse, printed_char = 0;
va_list conversion_specifier;

  if (format == NULL)
    {
      return (-1);
    }
  va_start(conversion_specifier, format);
  for (browse = 0; format[browse] != '\0'; browse++)
    {
      if (format[browse] != '%')
	{
	  write(1, &format[browse], 1);
	  printed_char++;
	}
          else
	{
	  browse++;
	  if (format[browse] == '\0')
	    break;
	  else if (format[browse] == 'c')
	    {
	      char c = va_arg(conversion_specifier, int);
	      write (1, &c, 1);
	      printed_char++;
	    }
	   else if (format[browse] == 's')
	    {
	      int str_length;
	      char *str = va_arg(conversion_specifier, char*);
	      if (str == NULL)
		{
	      str = "null";
		}
	      for (str_length = 0; str[str_length] != '\0'; str_length++)
		{
		  write (1, &str[str_length], 1);
		}
	    }
	  else if (format[browse] == '%')
	    {
	      write(1, "%", 1);
	      printed_char++;
	    }
	  /*integer*/
	  /*	  if (format[browse] == 'd' || format[browse] == 'i')
	    {
	      int number = va_arg(conversion_specifier, int);
	     	     
	      }*/
	}

    }
  va_end(conversion_specifier);
  return (printed_char);
} 
