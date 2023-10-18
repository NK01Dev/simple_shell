#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define DELIM " \t\n"
extern char **environ;
int _exec(char **cmnd, char **argv, int indx);
char *_getenviron(char *vrbl);
int is_builtinside(char *cmnd);
void handle_builtinside(char **cmnd, char **argv, int *stts, int indx);
void end_shell(char **cmnd, char **argv, int *stts, int indx);
void print_environ(char **cmnd, int *stts);
char *_getpath(char *cmnd);
char **spreader(char *line);
void freeTable(char **array);

char *read_line(void);
char *_itoa(int n);
void p_error(char *name, char *cmd, int idx);
void reverse_string(char *str, int len);

int check_if_positive(char *str);
int _atoi(char *str);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif

