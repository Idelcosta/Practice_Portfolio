#include <stdio.h>
#include "main.h"
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    unsigned int n;

    n = binary_to_uint("1");
    printf("%u\n", n);
    n = binary_to_uint("101");
    printf("%u\n", n);
    n = binary_to_uint("1e01");
    printf("%u\n", n);
    n = binary_to_uint("1100010");
    printf("%u\n", n);
    n = binary_to_uint("0000000000000000000110010010");
    printf("%u\n", n);
    return (0);
}



unsigned int binary_to_uint(const char *b)
{
        unsigned int value = 0;

        if (b == NULL)
                return (0);
        while (*b != '\0')
        {
                value = value << 1;
                if (*b != '1' && *b != '0')
                        return (0);
                else if (*b == '1')
                        value = value | 1;
                b++;
        }
        return (value);
}

