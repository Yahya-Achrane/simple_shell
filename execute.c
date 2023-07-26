#include "main.h"

/**
 * execute - executes a selk
 * @tok: array of tok
 * @av: array of arguments
 * @env: array of environment variables
 * Return: 0 on success, 1 on failure
 */

int execute(char **tok, char **av, char **env)
{
    char *selk = NULL;
    pid_t child_pid = 0;
    int i = 0;

    if (is_builtins(tok, av, env) == 0)
    {
        exit_cmd(1, 0);
        return (0);
    }
    selk = get_path(tok[0]);
    if (selk == NULL)
    {
        perror(av[0]);
        exit_cmd(1, 127);
        return (1);
    }
    if (!access(selk, X_OK))
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            perror(av[0]);
            return (1);
        }
        if (child_pid == 0)
        {
            if (execve(selk, tok, env) == -1)
            {
                perror(av[0]);
                free(selk);
                exit(1);
            }
        }
        else
            wait(&i);
        exit_cmd(1, 0);
    }
    else
    {
        perror(av[0]);
        exit_cmd(1, 126);
    }
    return (i);
}