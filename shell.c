#include "shell.h"
/**
* main - The main function of the shell.
* @param ac: Argument count
* @param av: Argument vector
* @param env: Environment variables
* Return: returns 0 on succ
*/

int main(int ac, char **av, char **env)
{
	char *block = NULL;
	size_t length = 0;
	ssize_t read_line = 0;
	int status = 0;
	char *huh;

	(void)ac;
	(void)av;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		read_line = getline(&block, &length, stdin);
		if (read_line == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (block[0] == '\n')
		continue;
		huh = ft_substr(block, 0, strlen(block) - 1);
		status = execute(huh, NULL, env, NULL);
	}
	free(block);
	return (status);
}
