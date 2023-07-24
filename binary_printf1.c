#include <stdio.h>
#include <stdarg.h>

int print_binary(unsigned int n);

/**
 * _printf - Custom printf function that handles format specifiers: b
 * @format: The format string containing the directives
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            putchar(*format);
            printed_chars++;
        }
        else
        {
            format++; /* Skip the '%' */

            /* Handle the format specifiers */
            switch (*format)
            {
                case 'b':
                    printed_chars += print_binary(va_arg(args, unsigned int));
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    printed_chars += 2;
                    break;
            }
        }

        format++;
    }

    va_end(args);

    return printed_chars;
}

