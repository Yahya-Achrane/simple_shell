#include "main.h"

/**
 * get_env - gets an environment variable
 * @name: name of the environment variable
 * Return: pointer to the environment variable
 */

char *get_env(char *key)
{
	unsigned int i = 0;
	char *path;
	char **env;
	int vect = 0, j = 0;

	while (environ[vect])
		vect++;

	env = malloc(sizeof(char *) * (vect + 1));

	for (j = 0; j < vect; j++)
		env[j] = _strdup(environ[j]);

	env[vect] = NULL;

	while (env[i])
	{
		path = strtok(env[i], "=");
		if (strcmp(key, env[i]) == 0)
		{
			path = strtok(NULL, "\n");
			return (path);
		}
		i++;
	}
	return (NULL);
}