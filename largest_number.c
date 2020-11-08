#include<stdio.h>
void main()
{
	int first_number, second_number;
	printf("Enter any two numbers: ");
	scanf("%d %d", &first_number, &second_number);
	if(first_number == second_number)
	{
		printf("Enter two unique numbers ");
	}
	if(first_number < second_number)
	{
		first_number = first_number + second_number;
		second_number = first_number - second_number;
		first_number = first_number - second_number;
	}
	printf("%d is larger than %d", first_number, second_number);
}