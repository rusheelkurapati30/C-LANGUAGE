#include<stdio.h>
void main()
{
	int no_of_odd_number, counter, odd_number = 1;
	printf("How many odd numbers do you want? ");
	scanf("%d", &no_of_odd_number);
	for(counter = 1; counter <= no_of_odd_number; counter++)
	{
		printf("%5d\n", odd_number);
		odd_number += 2;
	}
}