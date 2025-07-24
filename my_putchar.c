#include <unistd.h>
#include "main.h"
/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 *
 * Return: On success, returns (1). On error, return -1.
 */
int  my_putchar(char c)
{
	return (write(1, &c, 1));
}
