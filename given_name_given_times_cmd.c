//Print given name given number of times.

#include<stdio.h>
#include<stdlib.h>
void main(int argcount, char *arglist[])
{
	if(argcount == 3)
	{
		printf("The output is: \n");
		for(int counter = 0; counter < atoi(arglist[2]); counter++)
		{
			printf("%s\n", arglist[1]);
		}
	}
	else
	{
		printf("Invalid arguments, please use <name> <count of names>\n");
	}
}
