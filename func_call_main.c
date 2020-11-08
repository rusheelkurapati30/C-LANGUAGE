
//Write a function and call it from main().

#include<stdio.h>
int add(int number1, int number2)
{
	int sum;
	sum = number1 + number2;
	return sum;
}
void main()
{
	int number1, number2;
	printf("Enter number1: ");
	scanf("%d", &number1);
	printf("Enter number2: ");
	scanf("%d", &number2);
	int sum = add(number1, number2);
	printf("Sum of %d and %d is: %d\n", number1, number2, sum);
}	
	

/*#include<stdio.h>
int add(int n1, int n2)
{
	int sum = n1 + n2;
}
void main()
{
	int n1 = 5, n2 = 15, sum;
	sum =add(n1,n2);
	printf("Sum of %d and %d is: %d ", n1, n2, sum);
}*/

