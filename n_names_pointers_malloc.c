
// Read and print n marks using pointers and malloc().
// Read and print n names using pointer and malloc().
/*
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int no_of_names, no_of_chars,  ctr_name;
	char **ptr_name;
	printf("Enter the maximum number of names you want to print? \n");
	scanf("%d", &no_of_names);
	printf("Enter the maximum number of characters you want to print? \n");
	scanf("%d", &no_of_chars);
	ptr_name = (char**) malloc(no_of_names*sizeof(char*));
	printf("Enter %d names: \n", no_of_names);
	for(ctr_name = 0; ctr_name < no_of_names; ctr_name++)
	{
		ptr_name[ctr_name] = (char*) malloc(no_of_chars*sizeof(char));
		scanf("%s", ptr_name[ctr_name]);
	}
	printf("Displaying %d names: \n", no_of_names);
	for(ctr_name = 0; ctr_name < no_of_names; ctr_name++)
	{
		printf("%s\n", ptr_name[ctr_name]);
	}
}		

// Read and print n names using pointer and malloc().

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int no_of_names, no_of_char;
	char *ptr_marks;
	char *ptr_name = malloc(50);
	printf("Enter the maximum number of names you want to print? \n");
	scanf("%d", &no_of_names);
	printf("Enter the maximum number of characters you want to print? \n");
	scanf("%d", &no_of_char);
	char names[no_of_names][no_of_char],ctr_marks;
	ptr_marks = (char*) malloc(no_of_names*no_of_chars*sizeof(char));
	printf("Enter %d names: \n", no_of_names);
	for(ctr_marks = 0; ctr_marks < no_of_names; ctr_marks++)
	{
		printf("%u\n", ptr_name);
		scanf("%s", ptr_marks++);
	}
	printf("Displaying %d names: \n", no_of_names);
	for(ctr_marks = 0; ctr_marks < no_of_names; ctr_marks++)
	{
		printf("%s\n", ptr_marks++);
	}
}
*/

// Read and print n names using pointers and malloc().

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int no_of_names, no_of_chars, ctr_name, counter = 0;
	char *ptr_name;
	printf("Enter the maximum number of names you want to print: ");
	scanf("%d", &no_of_names);
	printf("Enter the maximum number of characters you want to print: ");
	scanf("%d", &no_of_chars);
	ptr_name = (char*) malloc(no_of_names*no_of_chars*sizeof(char));
	for(ctr_name = 0; ctr_name < no_of_names*no_of_chars; ctr_name += no_of_chars)
	{
		printf("Enter %d name: ", no_of_names);
		scanf("%s",ptr_name + ctr_name);
		counter++;
	}
	counter = 0;
	for(ctr_name = 0; ctr_name < no_of_names*no_of_chars; ctr_name += no_of_chars)
	{
		printf("name %d is: %s\n", no_of_names, ptr_name + ctr_name);
		counter++;
	}
}