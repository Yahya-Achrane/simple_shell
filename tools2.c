#include "main.h"

/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 * Return: pointer to the copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _constlen - counts the number of characters in a constant string
 * @str: constant string
 * Return: number of characters in the string
 */

int _constlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
/**
 * split_string - cuts a string when # is encountered
 * @str: string to be cut
 */
void *split_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			str[i] = '\0';
			break;
		}
		i++;
	}
	return (str);
}
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