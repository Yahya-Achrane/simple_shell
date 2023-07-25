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
#include <signal.h>

#define READ_SIZE 1024
#define BUFSIZE 1024

ssize_t _getline(char **buf, size_t *size_buf, int fild);

extern char **environ;

int execute(char **line);
char *ft_substr(char *s, unsigned int start, size_t len);
size_t _strlcpy(char *dst, const char *src, size_t dstsize);
char **create_tokens(char *line);
char *get_path(char *input);
int builtin_exit(char **args);
int builtin_env(char **args);
int builtin_cd(char **args);
int count_env(void);
void free_array(char **array);
void sig_Handler(int sig_num);

char *_strtok(char *str, const char *dem);
char *_strpbrk(char *str, const char *set);
int _strspn(char *str, const char *set);

#endif