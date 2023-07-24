#include <stdio.h>

/**
 * print_binary - Prints the binary representation of an unsigned integer
 * @n: The unsigned integer to be printed in binary
 *
 * Return: The number of characters printed
 */
int print_binary(unsigned int n)
{
    int count = 0;
    int size = sizeof(unsigned int) * 8; /* Number of bits in an unsigned int */
    int mask = 1 << (size - 1);          /* Start with the leftmost bit */
    int found_first_one = 0;

    while (mask > 0)
    {
        if (n & mask)
        {
            found_first_one = 1;
            putchar('1');
            count++;
        }
        else if (found_first_one || mask == 1)
        {
            putchar('0');
            count++;
        }

        mask >>= 1; /* Shift the mask one position to the right */
    }

    return count;
}

