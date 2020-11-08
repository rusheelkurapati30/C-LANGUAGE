
// Read and print 5 marks. 

#include <stdio.h>
#define NO_OF_MARKS 5
void main()
{
	int marks[NO_OF_MARKS], counter;
	printf("Enter %d marks: \n", NO_OF_MARKS);
	for(counter = 0; counter < NO_OF_MARKS; counter++)
	{
		scanf("%d", &marks[counter]);
	}
	printf("Displaying %d marks: \n", NO_OF_MARKS);
	for(counter = 0; counter < NO_OF_MARKS; counter++)
	{
		printf("%d\n", marks[counter]);
	}
}


