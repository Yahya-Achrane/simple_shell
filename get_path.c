#include "shell.h"

char *get_path(char *input)
{
	char *path, *token, *path_to_file, *env;
	struct stat cmd_stat;

	env = getenv("PATH");
	if (env)
	{
		path = strdup(getenv("PATH"));
		token = strtok(path, ":");
		while (token)
		{
			path_to_file = malloc(strlen(token) + strlen(input) + 2);
			strcpy(path_to_file, token);
			strcat(path_to_file, "/");
			strcat(path_to_file, input);
			strcat(path_to_file, "\0");
			if (stat(path_to_file, &cmd_stat) == 0)
			{
				free(path);
				return (path_to_file);
			}
			free(path_to_file);
			token = strtok(NULL, ":");
		}
		free(path);
		if (stat(input, &cmd_stat) == 0)
		{
			return strdup(input);
		}
		return (NULL);
	}
	return (NULL);
}



