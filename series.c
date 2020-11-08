#include<stdio.h>
void main()
{
	int no_of_terms, counter, product, term_counter;
	printf("Enter the number of terms do you want? ");
	scanf("%d", &no_of_terms);
	for(term_counter = 1; term_counter <= no_of_terms; term_counter++)
	{
		product = 1;
		for(counter = 1; counter <= term_counter; counter++)
		{
			product = product*term_counter;
			if(counter == term_counter)
				{
					printf("%d", product);
				}
		}
		if(term_counter < no_of_terms)
		{
			printf(",");
		}
		else{
			printf(".");	
		}
	}
}



	