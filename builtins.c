#include "main.h"

/**
 * builtins - handles the builtins
 * @tokens: array of strings
 * @env: environment variables
 * Return: 1 if the command is a builtin, 0 if not
 */

int is_builtins(char **tokens, char **env)
{
    if (buildin1(tokens, env))
        return (1);
    if (buildin2(tokens))
        return (1);
    if (buildin3(tokens))
        return (1);
    return (0);
}

/**
 * buildin1 - handles the builtins
 * @tokens: array of strings
 * @env: environment variables
 * Return: 1 if the command is a builtin, 0 if not
 */

int buildin1(char **tokens, char **env)
{
    int i = 0;

    if (_strncmp(tokens[0], "exit", 4) == 0)
        exit(EXIT_SUCCESS);
    if (_strncmp(tokens[0], "env", 3) == 0)
    {
        while (env[i] != NULL)
        {
            write(STDOUT_FILENO, env[i], _strlen(env[i]));
            write(STDOUT_FILENO, "\n", 1);
            i++;
        }
        return (1);
    }
    return (0);
}

/**
 * buildin2 - handles the builtins
 * @tokens: array of strings
 * Return: 1 if the command is a builtin, 0 if not
 */

int buildin2(char **tokens)
{
    if (_strncmp(tokens[0], "setenv", 6) == 0)
    {
        if (tokens[1] == NULL)
        {
            write(STDERR_FILENO, "Usage: setenv [VARIABLE] [VALUE]\n", 33);
            return (1);
        }
        if (tokens[2] == NULL)
        {
            return (1);
        }
        return (1);
    }
    if (_strncmp(tokens[0], "unsetenv", 8) == 0)
    {
        if (tokens[1] == NULL)
        {
            write(STDERR_FILENO, "Usage: unsetenv [VARIABLE]\n", 27);
            return (1);
        }
        return (1);
    }
    return (0);
}

/**
 * buildin3 - handles the builtins
 * @tokens: array of strings
 * Return: 1 if the command is a builtin, 0 if not
 */

int buildin3(char **tokens)
{
    if (_strncmp(tokens[0], "clear", 5) == 0)
    {
        write(STDOUT_FILENO, "\033[H\033[J", 6);
        return (1);
    }
    if (_strncmp(tokens[0], "echo", 4) == 0)
    {
        _echo(tokens, NULL);
        return (1);
    }
    if (_strncmp(tokens[0], "cd", 2) == 0)
    {
        _cd(tokens);
        return (1);
    }
    return (0);
}