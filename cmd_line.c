//Print sum of all command line argumenst (practise)

/*#include<stdio.h>
#include<stdlib.h>
void main(int argcount, char *arglist[])
{
	char *text;
	for (int counter = 1; counter < argcount; counter++)
	{
		text = arglist[counter];
		if (argcount > 1 && *text != '\0' && *text < '0' || *text > '9')
		{
			printf("%s is not a number\n", arglist[counter]);
		}
		else
		{		
			if(argcount > 1)
			{
				int counter, sum = 0;
				for(counter = 1; counter < argcount; counter++)
				{
					sum = sum + atoi(arglist[counter]);
				}
				printf("The sum is: %d\n", sum);
			}
			else	
			{
				printf("Invalid arguments please use: sum <number1> <number2> ....\n");
			}	
						
		}
	}

}*/

#include<stdio.h>
#include<stdlib.h>
void main(int argcount, char *arglist[])
{
	if(argcount == 3)
	{
	printf("output is: \n");
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








 