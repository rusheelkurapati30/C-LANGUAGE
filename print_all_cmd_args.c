//Print all command line arguments.

#include<stdio.h>
#include<stdlib.h>
void main(int argcount, char *arglist[])
{
	if(argcount == 1)
	{
		printf("No command line arguments are passed.");
	}
	int counter;
	for(counter = 1; counter < argcount; counter++)
	{
		printf("%s\n", arglist[counter]);
	}
}