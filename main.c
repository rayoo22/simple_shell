#include "main.h"
/**
 * main - 
 * @c:
 * @argv:
 * Return: 
*/
int main(int c, char **argv)
{
(void)c;
char *prompt = "(shell)> $ ";
char *buffer, *cpy_buff, *token;
size_t size = 0;
ssize_t num_chars;
const char *delim = " \n";
int num_tokens = 0, i;

prompt 
while (1)
{
printf("%s", prompt);
/* to get input from user */
num_chars = getline(&buffer, &size, stdin);

if (num_chars == -1)
{
printf("Exiting (shell)> $ .....\n");
return (-1);
}

cpy_buff = malloc(sizeof(char) * num_chars);
if (cpy_buff == NULL)
{
perror("Memory allocation failed\n");
return (-1);
}

strcpy(cpy_buff, buffer);

token = strtok(buffer, delim);

while (token != NULL)
{
num_tokens++;
token = strtok(NULL, delim);
}
num_tokens++;

argv = malloc(sizeof(char *) * num_tokens);

token = strtok(cpy_buff, delim);
for (i = 0; token != NULL; i++)
{
argv[i] = malloc(sizeof(char) * strlen(token));
strcpy(argv[i], token);

token = strtok(NULL, delim);

printf("%s\n", argv[i]);
}

/* printf("%s\n", buffer); */
}

free(cpy_buff);
free(argv);
free(buffer);

return (0);
}
