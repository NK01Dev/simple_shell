#include "shell.h"
/**
 * _getenviron - prints the current environment
 * @vrbl: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */

char *_getenviron(char *vrbl)
{
    char *temporary, *cle, *valeur, *env;
    int i;
    for (i = 0; environ[i]; i++)
    {
        temporary = _strdup(environ[i]);
        cle = strtok(temporary, "=");
        if (_strcmp(cle, vrbl) == 0)
        {
            valeur = strtok(NULL, "\n");
            env = _strdup(valeur);
            free(temporary);
            return (env);
        }
        free(temporary), temporary = NULL;
    }
    return (NULL);
}
