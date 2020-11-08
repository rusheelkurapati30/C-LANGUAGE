
// Read and print n marks using pointer and malloc().

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int ctr_marks, no_of_marks;
	int *ptr_marks;
	//char *ptr_name = malloc(50);
	printf("Enter maximum number of marks you want to print? \n");
	scanf("%d", &no_of_marks);
	ptr_marks = (int*) malloc(no_of_marks*sizeof(int));
	//ptr_marks = malloc(50);
	if(ptr_marks == NULL)
	{
		printf("Memory cannot be allocated.");
	}
	//printf("%d,%d\n", sizeof(ptr_name), sizeof(ptr_marks));
	printf("Enter %d marks: \n", no_of_marks);
	for(ctr_marks = 0; ctr_marks < no_of_marks; ctr_marks++)
	{
		//printf("%u\n", ptr_name++);
		//printf("%u\n", ptr_marks++);
		scanf("%d", ptr_marks+ctr_marks);
	}
	printf("Displaying %d marks: \n", no_of_marks);
	for(ctr_marks = 0; ctr_marks < no_of_marks; ctr_marks++)
	{
		printf("%d\n", *(ptr_marks+ctr_marks));
	}
}


// Read and print n marks using pointer and malloc().

/*#include<stdio.h>
#include<stdlib.h>
void main()
{
	int ctr_marks, no_of_marks;
	int *ptr_marks;
	char *ptr_name = malloc(50);
	printf("Enter maximum number of marks you want to print? \n");
	scanf("%d", &no_of_marks);
	ptr_marks = (int*) malloc(no_of_marks*sizeof(int));
	if(ptr_marks == NULL)
	{
		printf("Memory cannot be allocated.");
	}
	printf("%d,%d\n", sizeof(ptr_name), sizeof(ptr_marks));
	printf("Enter %d marks: \n", no_of_marks);
	for(ctr_marks = 0; ctr_marks < no_of_marks; ctr_marks++)
	{
		printf("%u\n", ptr_name++);
		//printf("%u\n", pointer);
		scanf("%d", ptr_marks++);
	}
	printf("Displaying %d marks: \n", no_of_marks);
	for(ctr_marks = 0; ctr_marks < no_of_marks; ctr_marks++)
	{
		printf("%d\n", ptr_marks++);
	}

}*/