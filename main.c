#include "main.h"
/**/

/**/
int main(int c, char **env)
{
char *prompt;
char *buffer;
char *arg[11];
char *delim;
size_t buffsize = 0;
ssize_t n_chars;
pid_t child_ID;
int status, i, j;
char *path;
(void)c;

prompt = "(Shell)$ ";
buffer = NULL;
delim = " \n";

prompt 
while (1)
{
if (isatty(0))
{
_printstring(prompt);
}

n_chars = getline(&buffer, &buffsize, stdin);
if (n_chars == -1)
{
_putchar('\n');
free(buffer);
exit(0);
}

i = 0;
while (buffer[i])
{
if (buffer[i] == '\n')
{
buffer[i] = 0;
}
i++;
}

j = 0;
arg[j] = my_strtok(buffer, delim);
while (arg[j])
{
arg[++j] = my_strtok(NULL, delim);
}
arg[j] = NULL;

path = get_loc(arg[0]);

if (path == NULL)
{
if (_builtInCmd(arg) != 0)
{
_printstring("cd");
continue;
}
else
{
_printstring("Command not found\n");
}
continue;
}

child_ID = fork();
if (child_ID < 0)
{
_printstring("Forking failed");
free(buffer);
exit(0);
}
else if (child_ID == 0)
{
if (execve(path, arg, env) == -1)
{
_printstring("Command does not exist\n");
}
}
else
{
wait(&status);
}
/* _printstring(buffer); */
}
free(path);
free(buffer);
return (0);
}
