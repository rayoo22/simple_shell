#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

unsigned int is_delim(char c, char *delim);
char *my_strtok(char *src, char *delim);
int _builtInCmd(char **arg);

int _putchar(char c);
int _printstring(char *str);
char *get_loc(char *arg);
char *location(char *path, char *arg);

#endif 
