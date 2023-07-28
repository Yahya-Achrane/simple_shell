#include "main.h"

/**
 * _printenv - prints the environment variables
 * @env: array of environment variables
 */

void _printenv(char **env)
{
    int i = 0, j = 0;

    while (env[i] != NULL)
    {
        j = 0;
        while (env[i][j] != '\0')
        {
            write(STDOUT_FILENO, &env[i][j], 1);
            j++;
        }
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}

/**
 * is_builtins - checks if a command is a builtin
 * @tok: array of tok
 * @av: array of arguments
 * @env: array of environment variables
 * Return: 0 if builtin, 1 if not
 */

int is_builtins(char **tok, char **av, char **env, char *ln)
{
    char *temp = NULL;
    char *var = NULL;
    (void)av;

    if (_strncmp(tok[0], "exit", 4) == 0)
    {
        h_exit(tok, ln);
        return (0);
    }
    if (_strncmp(tok[0], "env", 3) == 0)
    {
        _printenv(env);
        return (0);
    }
    if (_strncmp(tok[0], "echo", 4) == 0)
    {
        _echo(tok);
        return (0);
    }
    if (_strncmp(tok[0], "cd", 2) == 0)
    {
        _cd(tok);
        return (0);
    }
    if (_strncmp(tok[0], "setenv", 6) == 0)
    {
        if (tok[1] != NULL && tok[2] != NULL)
        {
            var = (char *)malloc(strlen(tok[2]) + 1);
            temp = (char *)malloc(strlen(tok[1]) + 1);
            if (var != NULL && temp != NULL)
            {
                strcpy(temp, tok[1]);
                strcpy(var, tok[2]);
                set(env, temp, var);
                free(var);
                free(temp);
            }
        }
    }
    return (1);
}
void set(char **environment, char *name, char *value)
{
    int i;

    for (i = 0; environment[i]; i++)
    {
        if (strcmp(environment[i], name) == 0)
        {
            free(environment[i]);
            environment[i] = strdup(value);
            return;
        }
    }

    environment[i] = strdup(name);
    strcat(environment[i], "=");
    strcat(environment[i], value);
    environment[++i] = strdup("a");
    environment[i] = '\0';
}