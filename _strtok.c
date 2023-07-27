#include "main.h"
/**
 * _strtok - tokenizes a string
 * @str: string to tokenize
 * @dem: delimiter
 * Return: pointer to the first token found
 */

char *_strtok(char *str, char *dem)
{
    static char *token;
    static char *next;
    char *delim_ptr;

    if (str != NULL)
        next = str;
    if (next == NULL)
        return (NULL);
    token = next;
    delim_ptr = _strchr(token, *dem);

    if (delim_ptr != NULL)
    {
        *delim_ptr = '\0';
        next = delim_ptr + 1;
    }
    else
        next = NULL;
    return (token);
}