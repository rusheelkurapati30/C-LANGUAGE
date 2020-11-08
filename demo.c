//Add two numbers.
/*#include<stdio.h>
void main()
{
	int number1, number2, sum = 0;
	printf("\nEnter 2 numbers: ");
	scanf("%d %d", &number1, &number2);
	sum = number1 + number2;
	printf("\nSum of %d and %d is: %d\n", number1, number2, sum);
}*/


//Multiply three numbers.
/*#include<stdio.h>
void main()
{
	int number1, number2, number3, product;
	printf("\nEnter any three numbers: ");
	scanf("%d %d %d", &number1, &number2, &number3);
	product = number1 * number2 * number3;
	printf("\nProduct of %d, %d, and %d is: %d\n", number1, number2, number3, product);
}*/


// Print n natural numbers.
/*#include<stdio.h>
void main()
{
	int no_of_natural_no;
	printf("\nHow many natural numbers do you want to print?: ");
	scanf("%d", &no_of_natural_no);
	for(int counter = 1; counter <= no_of_natural_no; counter++)
	{
		printf("%2d\n", counter);
	}
}
*/


// Print n even numbers.
/*#include<stdio.h>
void main()
{
	int even_no = 2, no_of_even_no;
	//printf("\nHow many even numbers do you want?: ");
	printf("\nUpto which even numbers do you want to print?: ");
	scanf("%d", &no_of_even_no);
	for(int counter = 1; counter <= no_of_even_no; counter++)
	{
		printf("%2d\n", even_no);
		even_no += 2;
	}
}
*/

// Print sum of n natural numbers.
// #include<stdio.h>
// void main()
// {
// 	int no_of_natural_no, sum = 0;
// 	printf("How many natural numbers do you want to sum? ");
// 	scanf("%d", &no_of_natural_no);
// 	for(int counter = 1; counter <= no_of_natural_no; counter++)
// 	{
// 		sum = sum + counter;
// 	}
// 	printf("Sum of %d natural numbers are: %d",no_of_natural_no, sum);

// }


//Print n odd numbers.
/*#include<stdio.h>
void main()
{
	int odd_no = 1, no_of_odd_no;
	printf("\nHow many odd numbers do you want?: ");
	scanf("%d", &no_of_odd_no);
	for(int counter = 1; counter <= no_of_odd_no; counter++)
	{
		printf("%2d\n", odd_no);
		odd_no += 2;
	}
}*/


// Print sum of cubes of n odd numbers.
/*#include <stdio.h>
void main()
{
	int no_of_odd_no, sum_of_cubes = 0, product = 1, odd_no = 1;
	printf("\nHow many cubes of odd numbers do you want to sum?: ");
	scanf("%d", &no_of_odd_no);
	for(int counter = 1; counter <= no_of_odd_no; counter++)
	{
		product = odd_no * odd_no * odd_no;
		sum_of_cubes = sum_of_cubes + product;
		odd_no += 2;
	}
	printf("\nSum of cubes of %d odd numbers is: %d\n", no_of_odd_no, sum_of_cubes);
}*/


// print multiplication of a given table.
/*#include<stdio.h>
void main(int argc, char const *argv[])
{
	int table_no;
	printf("\nEnter which multiplication table you want to print?: ");
	scanf("%d", &table_no);
	printf("\nMultiplication table of %d is: ", table_no);
	for(int counter = 1; counter <= 10; counter++)
	{
		printf("\n%2d x %2d = %3d", table_no, counter, table_no * counter);
	}
}*/
 

// print n to the power of n.
/*#include<stdio.h>
void main()
{
	int no_for_base_and_power, product;
	printf("\nEnter the value of base and power: ");
	scanf("%d", &no_for_base_and_power);
	product = no_for_base_and_power;
	for(int counter = 1; counter < no_for_base_and_power; counter++)
	{
		product = product * no_for_base_and_power;
	}
	printf("%d to the power of %d is: %d", no_for_base_and_power, no_for_base_and_power, product);
}*/


// Print m to the power of n.
/*#include<stdio.h>
void main()
{
	int base, power, product;
	printf("\nEnter the value of base and power: ");
	scanf("%d %d", &base, &power);
	product = base;
	for(int counter = 1; counter < power; counter++)
	{
		product = product * base;
	}
	printf("%d to the power of %d is: %d", base, power, product);
}*/


// Print table book.
/*#include<stdio.h>
void main()
{
	int table_no = 1, no_of_tables;
	printf("\nHow many tables do you want to print?: ");
	scanf("%d", &no_of_tables);
	for(int table_no = 1; table_no <= no_of_tables; table_no++)
	{
		printf("\n\nMultiplication table of %d is: \n", table_no);
		for(int counter = 1; counter <= 10; counter++)
		{
			printf("\n%2d x %2d = %2d", table_no, counter, table_no*counter);
		}
	}
}*/


// Print the series 1, 4, 27, ___ up to n terms.
/*#include<stdio.h>
void main()
{
	int no_of_terms, term = 1, product;
	printf("\nHow many terms do you want to print?: ");
	scanf("%d", &no_of_terms);
	for(int term = 1; term <= no_of_terms; term++)
	{
		product = 1;
		for(int counter = 1; counter <= term; counter++)
		{
			product = product * term;
			if(counter == term)
			{
				printf("%d", product);
			}
		}
		if(term < no_of_terms)
		{
			printf(",");
		}
		else
		{
			printf(".");
		}
	}
}*/


// Print whether a given number is prime or not.
// #include<stdio.h>
// #include<math.h>
// void main()
// {
// 	int given_number, is_prime = 1, square_root_of_num, factor_counter; 
// 	printf("Enter any number to check whether a given number is prime or not: \n");
// 	scanf("%d", &given_number);
// 	if(given_number <= 1)
// 	{
// 		is_prime = 0;
// 	}
// 	else if(given_number != 2)
// 	{
// 		if(given_number % 2 ==0)
// 		{
// 			is_prime = 0;
// 		}
// 	}
// 	else
// 	{
// 		square_root_of_num = sqrt(given_number);
// 		for(factor_counter = 3; factor_counter <= square_root_of_num; factor_counter+=2)
// 		{
// 			if(given_number % factor_counter == 0)
// 			{
// 				is_prime = 0;
// 			}	
// 		}	
// 	}
// 	if(is_prime == 0)
// 	{
// 		printf("%d is not a prime number.", given_number);
// 	}
// 	else
// 	{
// 		printf("%d is a prime number.", given_number);
// 	}
// }


// Read and print five marks.
// #include <stdio.h>
// #define NO_OF_MARKS 5
// void main()
// {
// 	int marks[NO_OF_MARKS], counter;
// 	printf("Enter %d marks: \n", NO_OF_MARKS);
// 	for(counter = 0; counter < NO_OF_MARKS; counter++)
// 	{
// 		scanf("%d", &marks[counter]);
// 	}
// 	printf("Displaying %d marks: \n", NO_OF_MARKS);
// 	for(counter = 0; counter < NO_OF_MARKS; counter++)
// 	{
// 		printf("%d\n", marks[counter]);
// 	}
// }


// Write a program to read and print 5 names using Array's.
// #include<stdio.h>

// #define NO_OF_Names 5
// #define NO_OF_CHAR 25
// void main()
// {
// 	char names[NO_OF_Names][NO_OF_CHAR],counter;
// 	printf("Enter %d names: \n", NO_OF_Names);
// 	for(counter = 0; counter < NO_OF_Names; counter++)
// 	{
// 		scanf("%24s", names[counter]);
// 	}
// 	printf("Displaying %d names: \n", NO_OF_Names);
// 	for(counter = 0; counter < NO_OF_Names; counter++)
// 	{
// 		printf("%s\n", names[counter]);

// 	}
// }	



