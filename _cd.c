#include "main.h"

void my_error(char *argv, int count, char *cmd, char *msg)
{
    char *str_count = NULL;

    write(STDERR_FILENO, argv, _strlen(argv));
    write(STDERR_FILENO, ": ", 2);
    str_count = _itoa(count);
    write(STDERR_FILENO, str_count, _strlen(str_count));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, msg, _strlen(msg));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, "\n", 1);
    free(str_count);
}

char **_path(char *q, char **arg)
{
    char *str1 = NULL;
    char **dir = NULL;
    str1 = get_env(q);
    if (str1 == NULL)
    {
        if (arg[1] == NULL)
            write(STDERR_FILENO, "cd: HOME not set\n", 17);
        else
            write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);
        return (NULL);
    }
    dir = malloc(sizeof(char *) * 2);
    if (dir == NULL)
        return (NULL);
    dir[0] = str1;
    dir[1] = NULL;
    return dir;
}

void cd_cd(char **dir, char *cmd_nm)
{
    char *pwd = getcwd(NULL, 0);

    if (chdir(dir[0]) == -1)
    {
        my_error(cmd_nm, 0, dir[0], "can't cd to ");
        return;
    }
    else
        free(pwd);
}

void _cd(char **arg)
{
    char **dir = NULL;

    if (arg[1] == NULL)
        dir = _path("HOME", arg);
    else if (_strncmp(arg[1], "-", 1) == 0)
        dir = _path("OLDPWD", arg);
    else
    {
        dir = malloc(sizeof(char *) * 2);
        if (dir == NULL)
            return;
        dir[0] = arg[1];
        dir[1] = NULL;
    }
    if (dir == NULL)
        return;
    cd_cd(dir, arg[0]);
    free(dir);
}
