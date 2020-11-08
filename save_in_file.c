
// Read a name and save it into a file.

#include<stdio.h>
void main()
{
	FILE *fp_names;
	char name[50];
	fp_names = fopen("file.txt","a");
	if(fp_names == NULL)
	{
		printf("File does not exit\n");
	}
	printf("Enter a name: ");
	gets(name);
	fprintf(fp_names, "Name:%s\n", name);
	fclose(fp_names);
}