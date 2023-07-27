#include "main.h"

/**
 * _cd - changes the current working directory
 * @args: arguments
 */

void _cd(char **args)
{
    char **d = NULL, *owd = NULL, *h = NULL;

    if (args[1] == NULL)
    {
        h = get_env("HOME");
        if (h == NULL)
        {
            write(STDERR_FILENO, "cd: HOME not set\n", 17);
            return;
        }
        d = malloc(sizeof(char *) * 2);
        if (d == NULL)
            return;
        d[0] = h;
        d[1] = NULL;
    }
    else if (_strncmp(args[1], "-", 1) == 0)
    {
        owd = get_env("OLDPWD");
        if (owd == NULL)
        {
            write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);
            return;
        }
        d = malloc(sizeof(char *) * 2);
        if (d == NULL)
            return;
        d[0] = owd;
        d[1] = NULL;
    }
    else
    {
        d = malloc(sizeof(char *) * 2);
        if (d == NULL)
            return;
        d[0] = args[1];
        d[1] = NULL;
    }
    cd_cd(d, args[0]);
    free(d);
}

/**
 * cd_cd - changes the current working directory
 * @dir: dir to change to
 * @cmd_nm: name of the command
 */

void cd_cd(char **dir, char *cmd_nm)
{
    char *pwd = getcwd(NULL, 0);

    if (chdir(dir[0]) == -1)
    {
        p_error(cmd_nm, 0, dir[0], "can't cd to ");
        return;
    }
    else
    {
        free(pwd);
    }
}
/**
 * p_error - prints an error message
 * @argv: name of the program
 * @count: number of commands entered
 * @cmd: command entered
 * @msg: error message
 */

void p_error(char *argv, int count, char *cmd, char *msg)
{
    char *str_count = NULL;

    write(STDERR_FILENO, argv, _constlen(argv));
    write(STDERR_FILENO, ": ", 2);
    str_count = _itoa(count);
    write(STDERR_FILENO, str_count, _constlen(str_count));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, msg, _constlen(msg));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, _constlen(cmd));
    write(STDERR_FILENO, "\n", 1);
    free(str_count);
}