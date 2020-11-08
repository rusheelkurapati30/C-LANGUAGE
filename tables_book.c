#include<stdio.h>
void main()
{
	int max_table_no, counter, table_number = 1, table_counter;
	printf("How many tables do you want? ");
	scanf("%d", &max_table_no);
	for(table_counter = 1; table_counter <= max_table_no; table_counter++)
	{
		printf("The multiplication table of %d is: \n", table_counter);
		for(counter = 1; counter <= 10; counter++)
		{
			printf("%3d x %3d = %3d\n", table_number, counter, table_number*counter);
		}			
		table_number++;
	}		 
}

