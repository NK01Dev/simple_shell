#include "shell.h"
/**
 * _getpath - determines if a file is an executable command
 * @cmnd: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
char *_getpath(char *cmnd)
{
char *path_environ, *full_cmnd, *dir;
struct stat st;
int i;

for (i = 0; cmnd[i]; i++)
{
if (cmnd[i] == '/')
{
if (stat(cmnd, &st) == 0)
return (_strdup(cmnd));
return (NULL);
}
}

path_environ = _getenviron("PATH");
if (!path_environ)
{
return (NULL);
}

dir = strtok(path_environ, ":");
while (dir)
{
full_cmnd = malloc(_strlen(dir) + _strlen(cmnd) + 2);
if (full_cmnd)
{
_strcpy(full_cmnd, dir);
_strcat(full_cmnd, "/");
_strcat(full_cmnd, cmnd);
if (stat(full_cmnd, &st) == 0)
{
free(path_environ);
return (full_cmnd);
}
free(full_cmnd), full_cmnd = NULL;
dir = strtok(NULL, ":");
}
}
free(path_environ);
return (NULL);
}
