//Print given text with underline of exact length
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printh(char*);
int main(int argcount, char* arglist[])
{
        /*char name[30];
        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);
        name[strlen(name) - 1] = '\0';
        */
        printh(arglist[1]);
}
void printh(char* string)
{
        for(int counter = 0, length = printf("%s\n", string); counter < length - 1; counter++)
        {
                printf("%c", '-');
        }
}