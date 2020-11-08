
// Read and print n marks.

#include <stdio.h>
void main()
{
	int count;
	printf("Enter the number of marks do you want to print? ");
	scanf("%d", &count);
	int marks[count], counter;
	printf("Enter %d marks: \n", count);
	for(counter = 0; counter < count; counter++)
	{
		scanf("%d", &marks[counter]);
	}
	printf("Displaying %d marks: \n", count);
	for(counter = 0; counter < count; counter++)
	{
		printf("%d\n", marks[counter]);
	}
}