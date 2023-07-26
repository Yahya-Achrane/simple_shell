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
int is_builtins(char **tok, char **av, char **env)
{
    (void)av;

    if (_strncmp(tok[0], "exit", 4) == 0)
    {
        if (tok[1] != NULL)
        {
            if (check_num(tok[1]))
            {
                exit(2);
                exit(_atoi(tok[1]));
            }
        }
        ffree(tok);
        exit(exit_cmd(0, 0));
    }
    if (_strncmp(tok[0], "env", 3) == 0)
    {
        _printenv(env);
        return (0);
    }
    return (1);
}
