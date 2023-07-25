#include "shell.h"

/**
 * execute - Executes a command in a child process and waits for it to complete
 * @line: The command to be executed
 * Return: The exit status of the executed command
 */
int execute(char **line)
{
	pid_t pid;
	int status;
	char *path;

	pid = fork();
	if (pid == 0)
	{

		if (line)
		{
			path = get_path(line[0]);
			if (execve(path, line, NULL) == -1)
			{
				perror("execve");
				return (1);
			}
			return (0);
		}
		exit(1);
	}
	else if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	else
	{
		do
		{
			status = waitpid(pid, NULL, WUNTRACED);
		} while (status == -1 && errno == EINTR);

		return (status);
	}
}

/**
 * ft_substr - Extracts a substring from a given string
 * @s: Pointer to the source string
 * @start: The starting index of the substring
 * @len: The maximum length of the substring
 * Return: A newly allocated string containing the extracted substring
 */

char *ft_substr(char *s, unsigned int start, size_t len)
{
	size_t slen;
	char *wee;

	if (!s)
	{
		free(s);
		return (0);
	}
	slen = strlen(s);
	if (slen < start)
		return (strdup(""));

	if (slen - start >= len)
		wee = malloc(len + 1);
	else
		wee = malloc(slen - start + 1);
	if (!wee)
		return (NULL);
	_strlcpy(wee, (s + start), len + 1);
	return (wee);
}

/**
 * _strlcpy - Safely copies a string to a destination buffer with a limited size
 * @dst: Pointer to the destination buffer
 * @src: Pointer to the source string to be copied
 * @dstsize: Size of the destination buffer
 * Return: The total length of the source string (not including the null-terminator)
 */
size_t _strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t l;

	i = 0;
	l = strlen(src);
	if (dst == src)
		return (l);
	if (dst == NULL && src == NULL)
		return (0);
	if (dstsize == 0)
		return (l);
	while (src[i] && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (l);
}
