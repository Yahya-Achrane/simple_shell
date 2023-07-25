#include "shell.h"
/**
 * main - The main function of the shell.
 * @ac: Argument count
 * @av: Argument vector
 * @env: Environment variables
 * Return: returns 0 on succ
 */

int main(int ac, char **av, char **env)
{
    char *block = NULL;
    size_t length = 0;
    ssize_t read_line = 0;
    int status = 0;
    char **tokens;

    (void)ac;
    (void)av;
    (void)env;

    signal(SIGINT, sig_Handler);
    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$ ", 2);
        read_line = _getline(&block, &length, STDIN_FILENO);
        if (read_line == -1)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            break;
        }
        if (block[0] == '\n')
            continue;
        tokens = create_tokens(block);
        if (strcmp(tokens[0], "env") == 0)
        {
		status = builtin_env(tokens);
        }
        else if (strcmp(tokens[0], "exit") == 0)
        {
		status = builtin_exit(tokens);
        }
	else if (strcmp(tokens[0], "cd") == 0)
	{
		status = builtin_cd(tokens);
	}
        else
        {
            status = execute(tokens);
        }
    }
    free(block);
    return (status);
}
