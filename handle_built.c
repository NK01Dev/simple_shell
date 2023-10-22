#include "shell.h"
/**
 * is_builtinside - checks if built it command
 * @cmnd: the input command line
 * Return: 1 or 0
 */
int is_builtinside(char *cmnd)
{

char *builtinside[] = {"exit", "env", "setenv", "cd", "unsetenv", NULL};
int i;

for (i = 0; builtinside[i]; i++)
{
if (_strcmp(cmnd, builtinside[i]) == 0)
return (1);
}

return (0);
}

/**
 * handle_builtinside - handles builtin command
 * @cmnd: the input command line
 * @argv: the arguments
 * @stts: exit value
 * @indx: the index
 * Return: void
 */

void handle_builtinside(char **cmnd, char **argv, int *stts, int indx)
{
if (_strcmp(cmnd[0], "setenv") == 0)
{
if (cmnd[1] && cmnd[2])
{
if (setenv(cmnd[1], cmnd[2], 1) != 0)
{
perror("setenv");
*stts = 2;
}
}
else
{
write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 30);
*stts = 2;
}
}
else if (_strcmp(cmnd[0], "unsetenv") == 0)
{
if (cmnd[1])
{
if (unsetenv(cmnd[1]) != 0)
{
perror("unsetenv");
*stts = 2;
}
}
else
{
write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
*stts = 2;
}
}
else if (_strcmp(cmnd[0], "exit") == 0)
end_shell(cmnd, argv, stts, indx);
else if (_strcmp(cmnd[0], "env") == 0)
print_environ(cmnd, stts);

}
/**
 * handle_cd - handles cd cmnd
 * @cmnd: the input command line
 * @stts: exit value
 * Return: void
 */
void handle_cd(char **cmnd, int *stts)
{
char *s, *dir, buffer[1024];
int chdir_ret;
s = getcwd(buffer, 1024);
if (!s)
perror("getcwd failure");
if (!cmnd[1])
{
dir = _getenviron("HOME");
if (!dir)
chdir_ret = chdir((dir = _getenviron("PWD")) ? dir : "/");
else
chdir_ret = chdir(dir); 
} 
else if (_strcmp(cmnd[1], "-") == 0)
{
char *oldpwd = _getenviron("OLDPWD");
if (!oldpwd)
{
write(STDOUT_FILENO, s, strlen(s));
write(STDOUT_FILENO, "\n", 1);
*stts = 1;
return;
}
write(STDOUT_FILENO, oldpwd, strlen(oldpwd));
write(STDOUT_FILENO, "\n", 1);
chdir_ret = chdir(oldpwd);
}
else
{
chdir_ret = chdir(cmnd[1]);
}
if (chdir_ret == -1)
{
perror("can't cd to ");
write(STDERR_FILENO, cmnd[1], strlen(cmnd[1]));
write(STDERR_FILENO, "\n", 1);
*stts = 1;
}else
{
setenv("OLDPWD", getenv("PWD"), 1);
setenv("PWD", getcwd(buffer, 1024), 1);
}
}





/**
 * end_shell - checks for illegal inputs
 * @cmnd: the input command line
 * @argv: the arguments
 * @stts: exit value
 * @indx: the index
 * Return: void
 */

void end_shell(char **cmnd, char **argv, int *stts, int indx)
{
int exit_value = (*stts);
char *index, mssg[] = ": exit: Illegal number: ";
if (cmnd[1])
{
if (check_if_positive(cmnd[1]))
{
exit_value = _atoi(cmnd[1]);
}
else
{
index = _itoa(indx);
write(STDERR_FILENO, argv[0], _strlen(argv[0]));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, index, _strlen(index));
write(STDERR_FILENO, mssg, _strlen(mssg));
write(STDERR_FILENO, cmnd[1], _strlen(cmnd[1]));
write(STDERR_FILENO, "\n", 1);
free(index);
freeTable(cmnd);
(*stts) = 2;
return;
}
}
freeTable(cmnd);
exit(exit_value);
}

/**
 * print_environ - checks for illegal inputs
 * @cmnd: the input command line
 * @stts: exit value
 * Return: void
 */

void print_environ(char **cmnd, int *stts)
{
int i;
for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
freeTable(cmnd);
(*stts) = 0;
}
