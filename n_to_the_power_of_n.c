#include<stdio.h>
void main(){
	int no_for_base_and_power,product, counter;
	printf("Enter the value for base and power: ");
	scanf("%d", &no_for_base_and_power);
	product = no_for_base_and_power;
	for(counter=1; counter < no_for_base_and_power; counter++)
	{
		product = product*no_for_base_and_power;
	}
	printf("%d to the power of %d is: %d",no_for_base_and_power, no_for_base_and_power, product);
}