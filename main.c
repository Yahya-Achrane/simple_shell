#include "main.h"

/**
 * main - starting point of the program
 * @ac: number of arguments
 * @av: array of arguments
 * @env: array of environment variables
 * Return: 0 on success, 1 on failure
 */

int main(int ac, char **av, char **env)
{
	char *block = NULL, **tok = NULL;
	size_t ln = 0;
	ssize_t read = 0;
	int status = 0;

	(void)ac;
	signal(SIGINT, sig_Handler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		read = getline(&block, &ln, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (block[0] == '\n')
			continue;
		split_string(block);
		tok = create_tokens(block);
		if (tok[0] == NULL)
		{
			free(tok);
			continue;
		}
		if (tok == NULL)
			continue;
		status = execute(tok, av, env);
		free(tok);
	}
	free(block);
	return (status);
}
