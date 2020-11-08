#include<stdio.h>
void main()
{
	int number1, number2, number3, product;
	printf("Enter any three numbers: ");
	scanf("%d %d %d", &number1, &number2, &number3);
	product = number1*number2*number3;
	printf("Product of %d, %d and %d is: %d", number1, number2, number3, product);
}