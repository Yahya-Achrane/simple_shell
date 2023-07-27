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

extern char **environ;

char **create_tokens(char *line);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
int execute(char **tokens, char **argv, char **env, char *ln);
int _strncmp(char *str1, char *str2, int n);
char *_strdup(char *str);
int _atoi(char *str);
char *_itoa(int n);
void sig_Handler(int sig_num);
void split_string(char *str);
int check_num(char *str);
int exit_cmd(int act, int stat);
void ffree(char **p);
void p_free(char *p);
char *get_env(char *name);
char *make_path(char *path, char *cmd);
char *get_path(char *cmd);
int is_builtins(char **tok, char **av, char **env, char *l);
char *_strcpy(char *dest, char *src);
char *_strpbrk(char *str, const char *acc);
int _strspn(char *str, const char *acc);
char *_strtok(char *str, const char *dem);
int _echo(char **tok);
int h_exit(char **tokens, char *line);
void _printv(int val);
void _printk(char **tok, int i);
void _perror(char **tokens, char **argv);
#endif