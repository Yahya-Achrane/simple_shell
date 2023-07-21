#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>

int execute(char **line);
char *ft_substr(char *s, unsigned int start, size_t len);
size_t _strlcpy(char *dst, const char *src, size_t dstsize);
char **create_tokens(char *line);
char *get_path(char *input);

#endif
