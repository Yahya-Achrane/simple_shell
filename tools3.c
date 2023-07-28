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
/**
 * _itoa - converts an integer to a string
 * @num: integer to be converted
 * Return: pointer to the converted string
 */

char *_itoa(int n)
{
    int i = 0, j = 0, k = 0, l = 0, m = 0;
    char *str = NULL;

    if (n == 0)
    {
        str = malloc(sizeof(char) * 2);
        if (str == NULL)
            return (NULL);
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    if (n < 0)
        l = 1;
    m = n;
    while (m != 0)
    {
        m /= 10;
        i++;
    }
    str = malloc(sizeof(char) * (i + 1 + l));
    if (str == NULL)
        return (NULL);
    if (l == 1)
        str[0] = '-';
    for (j = i - 1 + l; j >= l; j--)
    {
        k = n % 10;
        if (k < 0)
            k *= -1;
        str[j] = k + '0';
        n /= 10;
    }
    str[i + l] = '\0';
    return (str);
}
/**
 * check_num - checks if a string is a number
 * @str: string to check
 * Return: 0 if number, 1 if not
 */

int check_num(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return (1);
        i++;
    }
    return (0);
}