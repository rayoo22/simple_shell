#include "main.h"

char *location(char *path, char *arg) 
{
char *path_cpy, *pathToken, *filePath;
char *delim; /*buff;*/

delim = ":";
path_cpy = strdup(path);

pathToken = my_strtok(path_cpy, delim);

filePath = malloc(strlen(arg) + strlen(pathToken) + 2);
while (pathToken != NULL)
{
strcpy(filePath, pathToken);
strcat(filePath, "/");
strcat(filePath, arg);
strcat(filePath, "\0");

if (access(filePath, X_OK) == 0)
{
free(path_cpy);
return (filePath);
}
pathToken = my_strtok(NULL, delim);
}


free(filePath);
free(path_cpy);
/*
if (stat(arg, &buff) == 0)
{
return (arg);
}
*/
return (NULL);
}

char *get_loc(char *arg)
{
char *path;

path = getenv("PATH");

if (path)
{
path = location(path, arg);
return (path);
}
return (NULL);
}
