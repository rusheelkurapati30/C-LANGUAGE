#include<stdio.h>
void main()
{
	int no_of_names, no_of_chars;
	FILE *file_ptr;
	printf("Enter the maximum number of names you want to print? \n");
	scanf("%d", &no_of_names);
	printf("Enter the maximum number of characters you want to print? \n");
	scanf("%d", &no_of_chars);
	char names[no_of_names][no_of_chars], ctr_name;
	file_ptr = fopen("d:/Training/file.txt","w");
	if(file_ptr == NULL)
	{
		printf("File does not exit\n");
	}
	printf("Enter %d name: \n", no_of_names);
	for(ctr_name = 0; ctr_name < no_of_names; ctr_name++)
	{
	gets(names[ctr_name]);	
	fprintf(file_ptr, "%s\n",names);
	}
	fclose(file_ptr);
}