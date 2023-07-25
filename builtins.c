#include "shell.h"
/*
 * builtin_env - Prints the environment variables.
 * @args: The arguments passed to the function.
 * return: 0 on success, 1 on failure.
 */
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

/*
 * count_env - Counts the number of environment variables.
 * return: The number of environment variables.
 */
int count_env(void)
{
    int count = 0;

    while (environ[count])
    {
        count++;
    }

    return (count);
}

/*
 * free_array - Frees the memory allocated for an array of strings.
 *@array: The array of strings to free.
 *Return: Void.
 */
void free_array(char **array)
{
    int i;

    for (i = 0; array[i]; i++)
    {
        free(array[i]);
    }
    free(array);
}

/*
 * builtin_exit - Exits the shell.
 * args: The arguments passed to the function.
 * return: 0 on success, 1 on failure.
 */
int builtin_exit(char **args)
{
    if (args[1])
    {
	if (atoi(args[1]) == 0)
	{
		write(STDERR_FILENO, "exit: too many arguments\n", 22);
	}
	else
	{
		exit(atoi(args[1]));
	}
        return (1);
    }
    exit(0);
}

int builtin_cd(char **args)
{
	char *dir;

	if (args[1])
	{
		if (strcmp(args[1], "~") == 0 || strcmp(args[1], "-") == 0)
		{
			dir = getenv("HOME");
		}
		else
		{
			dir = malloc(strlen(args[1]) * sizeof(char *));
			strcpy(dir, args[1]);
		}
	}
	else
	{
		dir = getenv("HOME");
	}
		
	if (chdir(dir) != 0)
	{
		perror("chdir");
		return (1);
	}
	return (0);
}
