
// Read and print n names.

#include<stdio.h>
void main()
{
	int no_of_names, no_of_char;
	printf("Enter the maximum number of names you want to print? \n");
	scanf("%d", &no_of_names);
	printf("Enter the maximum number of characters you want to print? \n");
	scanf("%d", &no_of_char);
	char names[no_of_names][no_of_char],counter;
	printf("Enter %d names: \n", no_of_names);
	for(counter = 0; counter < no_of_names; counter++)
	{
		scanf("%s", names[counter]);
	}
	printf("Displaying %d names: \n", no_of_names);
	for(counter = 0; counter < no_of_names; counter++)
	{
		printf("%s\n", names[counter]);
	}
}