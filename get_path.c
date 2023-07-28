#include "main.h"

/**
 * make_path - creates a path to a command
 * @path: path to the command
 * @cmd: command to create the path to
 * Return: pointer to the path
 */
char *make_path(char *path, char *cmd)
{
	char *path_cmd = NULL;

	path_cmd = malloc(sizeof(char) * (_strlen(path) + _strlen(cmd) + 2));
	if (path_cmd == NULL)
		return (NULL);
	_strcpy(path_cmd, path);
	_strcat(path_cmd, "/");
	_strcat(path_cmd, cmd);
	return (path_cmd);
}

/**
 * get_path - gets the path of a command
 * @cmd: command to get the path of
 * Return: path of the command
 */
char *get_path(char *cmd)
{
	char *path = NULL, *path_cp = NULL, *token = NULL, *path_cmd = NULL;
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (cmd);
	if (cmd == NULL)
		return (NULL);
	if (cmd[0] == '/')
	{
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	path = get_env("PATH");
	path_cp = _strdup(path);
	token = _strtok(path_cp, ":");
	while (token != NULL)
	{
		path_cmd = make_path(token, cmd);
		if (stat(path_cmd, &st) == 0)
		{
			free(path_cp);
			return (path_cmd);
		}
		free(path_cmd);
		token = _strtok(NULL, ":");
	}
	free(path_cp);
	return (NULL);
}
