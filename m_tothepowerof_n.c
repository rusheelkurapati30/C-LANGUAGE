#include<stdio.h>
void main()
{
	int base, power, counter, product;
	printf("Enter a value for base: ");
	scanf("%d",&base);
	printf("Enter a value for power: ");
	scanf("%d",&power);
	product = base;
	for(counter = 1; counter < power; counter++)
	{
		product = product*base;
	}
	printf("%d to the power of %d is: %d", base, power, product);
}