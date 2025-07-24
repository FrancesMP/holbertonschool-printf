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
	int count = 0;     /* track numbers of character that will get printed */
	va_list list_args;

    char num_buffer[20];

	if (format == NULL)
	{
		return (-1); /* Error, because printf() doesn't work */
	}
	va_start(list_args, format); /* va_start(list_args,first agr after printf) */

	while (*format) /* loop that iterates throught the Chara of the string: format */
	{
		if (*format != '%')
		{
			/* to write output to stdout : stdout w write is represented by 1 */
			/* w am i writing , how manybyte we allocate:single char so 1 */
			write(1, format, 1);
			count++; /* counting */
		}
		else /* if format == % */
		{
			format++; /* incremention by 1, passe au prochain c, check next c */
			if (*format == '\0')
			{
				va_end(list_args);
				return (-1);
			}
			if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list_args, int);
				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{   

				char *str = va_arg(list_args, char *); /* char* is the same as string */
				int str_len = 0;
                /* If the string pointer is NULL, print "(null)". */
				if (str == NULL)
				{
					str = "(null)";
				}

				while (str[str_len] != '\0') /* calcul str of the string*/
					str_len++;

				write(1, str, str_len);  /* write the string to the stdout*/
				count += str_len;
			}
				else if (*format == 'd' || *format == 'i')
			{
				
				int value = va_arg(list_args, int);
                char* ptr = num_buffer;
                int temp_value;
				char* start_ptr;
				char* end_ptr;

                int size = 0;                           /*  variable pour la taille */

                                                        /*check le cas spécial de 0 EN PREMIER*/ 
                if (value == 0) {
                    *ptr++ = '0';
                } else {
                    /*Gère le signe Negatif*/ 
                    if (value < 0) {
                        *ptr++ = '-';                   /*Stocke le signe moins dans le buffer*/ 
                        value = -value;                 /*Convertit en positif pour la conversion*/ 
                    }
                                                        /*On initialise start_ptr ici, APRÈS le potentiel ajout du signe*/ 
                    start_ptr = ptr;                    /*Marque le début des chiffres (après le signe si présent)*/

                    temp_value = value; /*On peut l'initialiser ici*/ 

                    /*Convertit les chiffres en ordre inverse dans le buffer*/ 
                    while (temp_value > 0) {
                        *ptr++ = (temp_value % 10) + '0'; /*Convertit le chiffre en caractère*/ 
                        temp_value /= 10;
                    }

                    /*Inverse les chiffres dans le buffer pour les mettre dans le bon ordre*/ 
                    end_ptr = ptr - 1;              /*Pointeur sur le dernier chiffre écrit (initialisé ici)*/ 
                    while (start_ptr < end_ptr) {
                        char temp_char = *start_ptr;
                        *start_ptr = *end_ptr;
                        *end_ptr = temp_char;
                        start_ptr++;
                        end_ptr--;
                    }
                }
                *ptr = '\0'; /*Ajoute le terminateur nul à la fin de la chaîne dans le buffer*/ 

                /*Calcule la longueur de la chaîne numérique dans num_buffer*/ 
                for (size = 0; num_buffer[size] != '\0'; size++);           /*Ceci est nécessaire pour l'appel à write()*/ 

                                                        /*Écrit la chaîne numérique entière vers la sortie standard*/ 
                count += size;                          /*Ajoute la longueur du nombre au total des caractères imprimés*/ 

              

			}
		}
		format++;
	} 

	va_end(list_args);
	return (count);
}
