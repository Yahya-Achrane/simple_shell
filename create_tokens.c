#include "main.h"

/**
 * create_tokens - tokenizes a string
 * @line: string to create_tokens
 * Return: pointer to an array of tokens
 */

char **create_tokens(char *line)
{
    char **tokens = NULL;
    char *token = NULL;
    int i = 0, len = 0;

    len = _strlen(line);
    if (len == 0)
        return (NULL);
    tokens = malloc(sizeof(char *) * (len + 1));
    if (tokens == NULL)
    {
        perror("Fatal Error");
        return (NULL);
    }
    token = strtok(line, " \n\t\r");
    while (token != NULL)
    {
        tokens[i] = token;
        token = strtok(NULL, " \n\t\r");
        i++;
    }
    tokens[i] = NULL;
    return (tokens);
}

/**
 * split_string - cuts a string when # is encountered
 * @str: string to be cut
 */

void split_string(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '#')
        {
            str[i] = '\0';
            return;
        }
        i++;
    }
}