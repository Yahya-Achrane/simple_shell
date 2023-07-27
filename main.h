#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define READ_SIZE 1024
#define BUFSIZE 1024

ssize_t _getline(char **buf, size_t *size_buf, int fild);

extern char **environ;

char **tokenizer(char *str, char *delim);
int get_input(char *buf, char **env, char **av);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
int _exec(char **tokens, char **env, char **av);
int f_run(char **tokens, char **env);
int ccmd(char *cmd);
int _strncmp(char *str1, char *str2, int n);
char *_strdup(char *str);
int _atoi(char *str);
char *_itoa(int n);
void sig_Handler(int sig_num);
void _perror(char **tokens, char **av);
void *split_string(char *str);
char *get_env(char *key);
char *make_path(char *path, char *cmd);
char *get_path(char *cmd);
int is_builtins(char **tokens, char **env);
int buildin1(char **tokens, char **env);
int buildin2(char **tokens);
int buildin3(char **tokens);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, char *dem);
int _echo(char **tokens, int *status);
char *_getenv(char *src);
void _echoargs(char *tokens, int *status);
void _cd(char **args);
void cd_cd(char **dir, char *cmd_nm);
int _constlen(const char *str);
void p_error(char *argv, int count, char *cmd, char *msg);
int _strcmp(char *str1, char *str2);
char *_strchr(char *s, char c);
char *_strcatpath(char *dest, char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
#endif