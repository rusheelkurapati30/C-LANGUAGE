#include <stdio.h>
void main()
{
	int no_of_odd_numbers, product, counter, odd_number = 1, sum_of_cubes = 0;
	printf("Sum of cubes of how many odd numbers do you want? ");
	scanf("%d", &no_of_odd_numbers);
	for(counter = 1; counter <= no_of_odd_numbers; counter++)
	{
		product = odd_number*odd_number*odd_number;
		sum_of_cubes = sum_of_cubes+product;
		odd_number = odd_number+2;
	}
	printf("Sum of cubes of %d odd numbers is: %d", no_of_odd_numbers, sum_of_cubes);

}
