
// print multiplication table of a given number.

#include<stdio.h>
void main()
{
	int table_number, counter;
	printf("Enter a table number: ");
	scanf("%d", &table_number);
	for(counter = 1; counter <= 10; counter++)
	{
		printf("%2d x %2d = %3d\n", table_number, counter, table_number * counter);
	}
	
}