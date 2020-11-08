#include<stdio.h>
void main()
{
    int no_of_natural_numbers, counter, sum=0;
    printf("How many natural numbers do you want to sum? ");
    scanf("%d", &no_of_natural_numbers);
    for(counter = 1; counter <= no_of_natural_numbers; counter++)
    {
        sum = sum + counter;
    }
    printf("Sum of %d natural numbers is: %d\n", no_of_natural_numbers, sum);
}