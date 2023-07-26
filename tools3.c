#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @str: string to be converted
 * Return: integer value of the string
 */

int _atoi(char *str)
{
    int i = 0, s = 1, n = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '-')
            s *= -1;
        if (str[i] >= '0' && str[i] <= '9')
            n = n * 10 + s * (str[i] - '0');
        if (n != 0 && !(str[i] >= '0' && str[i] <= '9'))
            break;
        i++;
    }
    return (n);
}