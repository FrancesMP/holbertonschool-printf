#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


/*main function*/
int _printf(const char *format, ...);

/* helpers */
int _putchar(char c);
int print_char(va_list args);	/* handles %c */
int print_string(va_list args);	/* handles %s */
int print_percent(va_list args);	/* handles % */
int print_integer(va_list args);
int _handle_format(const char *format, va_list args, int *i);

#endif

