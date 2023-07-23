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
	char **tokens;

	(void)ac;
	(void)av;
	(void)env;
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
		tokens = create_tokens(block);
		status = execute(tokens);
	}
	free(block);
	return (status);
}
