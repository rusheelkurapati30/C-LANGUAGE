#include<stdio.h>
void main()
{
	int no_of_natural_numbers, counter;
	printf("How many natural numbers do you want? ");
	scanf("%d", &no_of_natural_numbers);
	for(counter = 1; counter <= no_of_natural_numbers; counter++)
	{
		printf("%2d\n", counter);
	}
}