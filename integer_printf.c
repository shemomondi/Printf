#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function that handles format specifiers: d and i
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
            format++;

            
            switch (*format)
            {
                case 'd':
                case 'i':
                    printed_chars += printf("%d", va_arg(args, int));
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

