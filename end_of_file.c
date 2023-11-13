#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* fp = fopen("user_input.c", "r");

    int ch = getc(fp);

    while (ch != EOF)
    {
        putchar(ch);

        ch = getc(fp);
    }

    if (feof(fp))
    {
        printf("success");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("\n Something went wrong.");
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    getchar();
    return (0);
}