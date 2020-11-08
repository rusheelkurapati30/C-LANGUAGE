#include<stdio.h>
void main()
{
	int no_of_even_numbers, counter, even_number = 2;
	printf("How many even numbers do you want? ");
	scanf("%d", &no_of_even_numbers);
	for(counter = 1; counter <= no_of_even_numbers; counter++)
	{
		printf("%5d\n",even_number);
		even_number += 2;

	}
}