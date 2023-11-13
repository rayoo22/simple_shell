#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printPathDirectories()
{
    char *path = getenv("PATH");

    if (path == NULL)
    {
        printf("PATH environment variable not found\n");
        return;
    }

    char *token = strtok(path, ":");

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }
}

int main()
{
    printPathDirectories();
    return (0);
}
