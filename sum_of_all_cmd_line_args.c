//Print sum of all command line arguments.

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void main(int argcount, char *arglist[])
{
	int counter;
	if(argcount == 1)
	{
		int max_numbers, sum = 0;
		printf("How many numbers do you want to add? Press 0 to exit.\n");
		scanf("%d", &max_numbers);
		if(max_numbers == 0)
		{
			exit(0);
		}
		while(max_numbers < 2)
		{
			printf("Enter minimum 2 numbers to add: \n");
			scanf("%d", &max_numbers);
		}
		int  number[max_numbers];
		printf("Enter %d numbers: \n", max_numbers);
		for(counter = 0; counter < max_numbers; counter++)
		{
			scanf("%d", &number[counter]);
		}
		for(counter = 0; counter < max_numbers; counter++)
		{
			sum = sum + number[counter];
		}
		printf("The sum of %d numbers is: %d\n", max_numbers, sum);
		exit(0);
	}
	if(argcount > 1)
	{
		for(counter = 1; counter < argcount; counter++)
		{
			if(isdigit(*arglist[counter]) == 0)
			{
				printf("%s is not a number, please use valid number.\n", arglist[counter]);
				exit(0);
			}
		}
	}
	if(argcount > 2)
	{
		int counter, sum = 0;
		for(counter = 1; counter < argcount; counter++)
		{
			sum = sum + atoi(arglist[counter]);
		}
		if(sum > 0)
		{
			printf("The sum of %d numbers is: %d\n", argcount-1, sum);	
			//printf("Total is: %d\n", sum);
		}
	}
	else
	{
		printf("Invalid arguments, please use: sum <number1> <number2> ...\n");
	}
}