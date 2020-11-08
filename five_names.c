
// Write a program to read and print 5 names using Array's.

#include<stdio.h>

#define NO_OF_Names 5
#define NO_OF_CHAR 25
void main()
{
	char names[NO_OF_Names][NO_OF_CHAR],counter;
	printf("Enter %d names: \n", NO_OF_Names);
	for(counter = 0; counter < NO_OF_Names; counter++)
	{
		scanf("%24s", names[counter]);
	}
	printf("Displaying %d names: \n", NO_OF_Names);
	for(counter = 0; counter < NO_OF_Names; counter++)
	{
		printf("%s\n", names[counter]);

	}
}	

