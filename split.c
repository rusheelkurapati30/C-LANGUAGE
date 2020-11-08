
// strtok() to split the given string into words.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void split(char string[], char delim[])
{
	char *token = strtok(string, delim);
	while(token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
}
void main()
{
	char string[100];
	printf("\nEnter the string: ");
	gets(string);
	char delim[] = " ";
	split(string, delim);
}