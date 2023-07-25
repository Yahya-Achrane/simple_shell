#include "shell.h"

/**
 * _strtok - tokenize  string
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