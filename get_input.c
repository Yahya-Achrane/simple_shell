#include "main.h"

/**
 * tokenizer - tokenizes a string using a delimiter
 * @str: string to tokenize
 * @delim: delimiter
 * Return: array of toks
 */

char **tokenizer(char *str, char *delim)
{
    char **toks = NULL;
    char *token = NULL;
    int i = 0, size = 0;

    if (str == NULL)
        return (NULL);
    size = _strlen(str);
    toks = malloc(sizeof(char *) * size);
    if (toks == NULL)
        return (NULL);
    token = strtok(str, delim);
    while (token != NULL)
    {
        toks[i] = token;
        token = strtok(NULL, delim);
        i++;
    }
    toks[i] = NULL;
    return (toks);
}

/**
 * get_input - handles the input from the user and executes it
 * handling ; and run multiple commands
 * @buf: buffer to store the input
 * @env: environment variables
 * @av: arguments vector
 * Return: 0 on success
 */

int get_input(char *buf, char **env, char **av)
{
    char **toks = NULL, **cmd = NULL;
    int i = 0, size = 0;

    size = _strlen(buf);
    cmd = malloc(sizeof(char *) * size);
    if (cmd == NULL)
        return (-1);
    toks = tokenizer(buf, ";\n");
    while (toks[i] != NULL)
    {
        cmd = tokenizer(toks[i], " \t\r\n\a");
        if (cmd[0] != NULL)
            _exec(cmd, env, av);
        free(cmd);
        i++;
    }
    free(toks);
    return (0);
}