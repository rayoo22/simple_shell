#include "main.h"

char *location(char *path, char *arg)
{

}

char *get_loc(char *arg)
{
char *path;
if (access("PATH", X_OK) == 0)
{
path = getenv("PATH");
}
if (path)
{
path = 
}
}