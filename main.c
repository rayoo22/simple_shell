#include "main.h"
/**/
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**/
int _printstring(char *str)
{
int i = 0, count = 0;

while (str[i])
{
count += _putchar(str[i++]);
}
return (count);
}
/**/
int main(int c, char **env)
{

char *prompt;
char *buffer;
char *arg[10];
char *delim;
size_t buffsize = 0;
ssize_t n_chars;
pid_t child_ID;
int status, i, j;
(void)c;

prompt = "(Shell)$ ";
buffer = NULL;
delim = " \n";

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
arg[j] = strtok(buffer, delim);
while (arg[j])
{
arg[++j] = strtok(NULL, delim);
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
if (execve(arg[0], arg, env) == -1)
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

free(buffer);
return (0);
}
