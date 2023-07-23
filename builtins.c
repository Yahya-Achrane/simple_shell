#include "shell.h"

int builtin_env(char **args)
{
    int i;
    char **env_cpy;

    if (args[1])
    {
        write(STDERR_FILENO, "env: too many arguments\n", 22);
        return (1);
    }

    env_cpy = malloc(sizeof(char *) * (count_env() + 1));
    if (!env_cpy)
    {
        write(STDERR_FILENO, "env: malloc failed\n", 18);
        return (1);
    }

    for (i = 0; environ[i]; i++)
    {
        env_cpy[i] = strdup(environ[i]);
    }
    env_cpy[i] = NULL;

    for (i = 0; env_cpy[i]; i++)
    {
        write(STDOUT_FILENO, env_cpy[i], strlen(env_cpy[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    free_array(env_cpy);

    return (0);
}

int count_env(void)
{
    int count = 0;

    while (environ[count])
    {
        count++;
    }

    return (count);
}

void free_array(char **array)
{
    int i;

    for (i = 0; array[i]; i++)
    {
        free(array[i]);
    }
    free(array);
}

int builtin_exit(char **args)
{
    if (args[1])
    {
        write(STDERR_FILENO, "exit: too many arguments\n", 22);
        return (1);
    }

    exit(0);
}