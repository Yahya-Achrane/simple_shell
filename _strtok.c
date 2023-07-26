#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @str: string to be searched
 * @acc: string containing the characters to match
 * Return: number of bytes in the initial segment of str
 * which consist only of bytes from acc
 */

int _strspn(char *str, const char *acc)
{
    int i = 0, j = 0, count = 0;

    while (str[i] != '\0')
    {
        j = 0;
        while (acc[j] != '\0')
        {
            if (str[i] == acc[j])
            {
                count++;
                break;
            }
            j++;
        }
        if (acc[j] == '\0')
        {
            break;
        }
        i++;
    }

    return count;
}

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @str: string to be searched
 * @acc: string containing the characters to match
 * Return: pointer to the byte in str that matches one of the bytes in acc
 * or NULL if no such byte is found
 */

char *_strpbrk(char *str, const char *acc)
{
    int i = 0, j = 0;

    while (str[i] != '\0')
    {
        j = 0;
        while (acc[j] != '\0')
        {
            if (str[i] == acc[j])
            {
                return (str + i);
            }
            j++;
        }
        i++;
    }

    return NULL;
}

/**
 * _strtok - tokenizes a string
 * @str: string to tokenize
 * @dem: delimiter to tokenize by
 * Return: pointer to an array of tokens
 */

char *_strtok(char *str, const char *dem)
{
    static char *lastToken = NULL;
    char *token;

    if (str == NULL)
    {
        str = lastToken;
    }

    if (str == NULL)
    {
        return NULL;
    }

    token = str;
    str += _strspn(str, dem);

    if (*str == '\0')
    {
        lastToken = NULL;
        return NULL;
    }

    token = str;
    str = _strpbrk(str, dem);

    if (str == NULL)
    {
        lastToken = NULL;
    }
    else
    {
        *str = '\0';
        lastToken = str + 1;
    }

    return token;
}