/*#include<stdio.h>
void main()
{
	
	FILE *ptr;
	char name[20];
	ptr = fopen("d:/Training/file.txt","r");
	while(fscanf(ptr, "%s", name)!=EOF)
	{
		printf("%s", name);
	}
	
}*/

// Print all the names from the file.

#include<stdio.h>
void main()
{
	
	FILE *fp_names;
	char name[50];
	fp_names = fopen("file.txt", "r");
	while(fgets(name, 30, fp_names) != NULL)
	{
		printf("%s", name);
	}
	fclose(fp_names);
}

