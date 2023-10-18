#include "shell.h"

int is_builtinside(char *cmnd)
{

   char *builtinside[] = {"exit", "env", "setenv", "cd", NULL};
   int i;

   for (i = 0; builtinside[i]; i++)
   {
      if (_strcmp(cmnd, builtinside[i]) == 0)
         return (1);
   }

   return (0);
}

void handle_builtinside(char **cmnd, char **argv, int *stts, int indx)
{

   if (_strcmp(cmnd[0], "exit") == 0)
      end_shell(cmnd, argv, stts, indx);
   else if (_strcmp(cmnd[0], "env") == 0)
      print_environ(cmnd, stts);
}

void end_shell(char **cmnd, char **argv, int *stts, int indx)
{
   int exit_value = (*stts);
   char *index, mssg[] = ": exit: Illegal number:";
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

