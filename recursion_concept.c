//Sum of natural numbers using Recursion. 

// #include <stdio.h>
// int sum(int given_number);

// int main()
// {
//     int number, result;
//     printf("Enter a positive integer: ");
//     scanf("%d", &number);
//     result = sum(number);
//     printf("sum = %d", result);
//     return 0;
// }
// int sum(int given_number)
// {
//     if (given_number != 0)
//         return given_number + sum(given_number-1); 
//     else
//         return given_number;
// }

#include <stdio.h>  
int fact (int);  
int main()  
{  
    int number,result;  
    printf("Enter the number whose factorial you want to calculate?");  
    scanf("%d",&number);  
    result = fact(number);  
    printf("factorial = %d",result);  
}  
int fact(int number)  
{  
    if (number==0)  
    {  
        return 0;  
    }  
    else if ( number == 1)  
    {  
        return 1;  
    }  
    else   
    {  
        return number*fact(number-1);  
    }  
}  