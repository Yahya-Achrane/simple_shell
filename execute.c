#include "main.h"

/**
 * _perror - prints an error message
 * @tokens: tokens
 * @av: argv
 * Return: void
 */

void _perror(char **tokens, char **av)
{
	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": line 1: ", 10);
	write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
	write(STDERR_FILENO, ": command not found\n", 20);
}

/**
 * f_run - forks and runs a command
 * @tokens: tokens
 * @env: environment variables
 * Return: 0 on success, 1 on failure.
 */

int f_run(char **tokens, char **env)
{
	pid_t pid;
	int status;
	char *path;
	struct stat st;

	if (stat(tokens[0], &st) == 0)
		path = _strdup(tokens[0]);
	else
		path = get_path(tokens[0]);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		free(path);
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(path, tokens, env) == -1)
		{
			perror("Error");
			free(path);
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
	free(path);
	return (0);
}
/**
 * ccmd - checks if a command exits
 * @cmd: command to check
 * Return: 1 if exits, 0 if not
 */

int ccmd(char *cmd)
{
	char *path = NULL;
	char *path_copy = NULL;
	char *token = NULL;
	char *cmd_path = NULL;
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (1);
	if (cmd == NULL)
		return (0);
	if (cmd[0] == '/')
	{
		if (stat(cmd, &st) == 0)
			return (1);
		return (0);
	}
	path = _getenv("PATH");
	path_copy = _strdup(path);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		cmd_path = malloc(sizeof(char) * (_strlen(token) + _strlen(cmd) + 2));
		_strcpy(cmd_path, token);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, cmd);
		if (stat(cmd_path, &st) == 0)
		{
			free(path_copy);
			free(cmd_path);
			return (1);
		}
		free(cmd_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (0);
}

/**
 * _exec - runs a command
 * @tokens: tokens
 * @env: environment variables
 * @av: argv
 * Return: 0 on success, 1 on failure.
 */

int _exec(char **tokens, char **env, char **av)
{
	int is_built_in = 0, cmd_exits = 0;

	is_built_in = is_builtins(tokens, env);
	cmd_exits = ccmd(tokens[0]);
	if (is_built_in == 0 && cmd_exits == 1)
	{
		f_run(tokens, env);
		return (0);
	}
	if (is_built_in == 0 && cmd_exits == 0)
	{
		_perror(tokens, av);
		return (1);
	}
	return (0);
}