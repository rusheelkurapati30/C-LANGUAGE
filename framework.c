#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MENU_FILE "menu.cfg"
#define FIELDS_FILE "fields.cfg"
#define DATABASE_FILE "database1.dat"
void create();
void display();
void search();
void update();
void delete();
void count_of_fields();
void field_list();
char menu_line[60];
int count_of_field_values = 0, count_of_field_names, record_found;
FILE *fp, *fp_data;
char field_name[40], field_value[40], search_value[40];
char **list_of_fields;
char active[10] = "active";
char inactive[10] = "inactive";
void main()
{
	count_of_fields();
	field_list();
	int choice;
	fp = fopen(MENU_FILE, "r");
	while(1)
	{
		while(fgets(menu_line, sizeof(menu_line), fp))
		{
			printf("\n%s", menu_line);
		}
		scanf("%d", &choice);
		fflush(stdin);
		switch(choice)
		{
			case 1: create();
			break;
			case 2: display();
			break;
			case 3: update();
			break;
			case 4: search();
			break;
			case 5: delete();
			break;
			case 6: exit(0);
			break;
			default:
			printf("\nInvalid choice!\n");
			break;
		}
		rewind(fp);
	}
	fclose(fp);
}
void count_of_fields()
{
	FILE *fp_count_of_fields;
	fp_count_of_fields = fopen(FIELDS_FILE, "r");
	while(fgets(field_name, sizeof(field_name), fp_count_of_fields))
	{
		count_of_field_values++;
	}
	count_of_field_names = count_of_field_values;
	//printf("count of fields: %d", count_of_field_values);
	fclose(fp_count_of_fields);
}
void field_list()
{
	fp = fopen(FIELDS_FILE, "r");
	list_of_fields = malloc(count_of_field_names * sizeof(char*));
	count_of_field_values = 0;
	while(fgets(field_name, sizeof(field_name), fp))
	{
		list_of_fields[count_of_field_values] = malloc(count_of_field_names * sizeof(char*));
		strcpy(list_of_fields[count_of_field_values], field_name);
		list_of_fields[count_of_field_values][strlen(list_of_fields[count_of_field_values]) - 1] = '\0';
		//printf("\n%s", list_of_fields[count_of_field_values]);
		count_of_field_values++;
	}
	fclose(fp);
}
void create()
{
	int no_of_records;
	record_found = 0;
	fp_data = fopen(DATABASE_FILE, "a+");
	printf("\nHow many records do you want to create?: ");
	scanf("%d", &no_of_records);
	fflush(stdin);
	for(int record = 0; record < no_of_records; record++)
	{
		count_of_field_values = 0;
		printf("\nEnter record %d: \n", record + 1);
		fwrite(active, sizeof(field_value), 1, fp_data);
		while(count_of_field_values < count_of_field_names)
		{
			printf("\nEnter %s: ", list_of_fields[count_of_field_values]);
			gets(field_value);
			fwrite(field_value, sizeof(field_value), 1, fp_data);
			count_of_field_values++;
			record_found++;
		}
	}
	if(record_found == 0)
	{
		printf("\nFile does not exist\n");
	}
	fclose(fp_data);	
}
void display()
{	
	fp_data = fopen(DATABASE_FILE, "r+");
	record_found = 0;
	if(fp_data != NULL)
	{
		fseek(fp_data, 0, SEEK_SET);
		while(fread(field_value, sizeof(field_value), 1, fp_data))
		{
			if(strcmp(active, field_value) == 0)
			{
				printf("\n");
				count_of_field_values = 0;
				while(count_of_field_values < count_of_field_names)
				{
					record_found++;
					fread(field_value, sizeof(field_value), 1, fp_data);
					printf("\n%s is: %s\n", list_of_fields[count_of_field_values], field_value);
					if(count_of_field_values == count_of_field_names - 1)
					{
						break;
					}
					count_of_field_values++;
				}
			}
		}
	}
	if(record_found == 0)
	{
		printf("\nFile does not exist.\n");
	}
	fclose(fp_data);
}
void search()
{
	fp_data = fopen(DATABASE_FILE, "r");
	record_found = 0;
	if(fp_data != NULL)
	{
		printf("\nEnter %s to search: ", list_of_fields[0]);
		gets(search_value);
		while(fread(field_value, sizeof(field_value), 1, fp_data))
		{
			if(strcmp(active, field_value) == 0)
			{
				fread(field_value, sizeof(field_value), 1, fp_data);
				if(strcmp(search_value, field_value) == 0)
				{
					count_of_field_values = 0;
					while(count_of_field_values < count_of_field_names)
					{
						record_found++;
						printf("\n%s is: %s\n", list_of_fields[count_of_field_values], field_value);
						fread(field_value, sizeof(field_value), 1, fp_data);
						if(count_of_field_values == count_of_field_names - 1)
						{
							break;
						}
						count_of_field_values++;
					}
					break;
				}

			}

		}
	}
	if(record_found == 0)
	{
		printf("\nField not found.\n");
	}
	fclose(fp_data);
}
void update()
{
	fp_data = fopen(DATABASE_FILE, "r+");
	record_found = 0;
	if (fp_data != NULL)
	{
		int choice;
		printf("\nEnter %s to update: ", list_of_fields[0]);
		gets(search_value);
		fseek(fp_data, 0, SEEK_SET);
		while(fread(field_value, sizeof(field_value), 1, fp_data))
		{
			if(strcmp(active, field_value) == 0)
			{
				fread(field_value, sizeof(field_value), 1, fp_data);
				if(strcmp(search_value, field_value) == 0)
				{
					record_found++;
					count_of_field_values = 0;
					printf("\nPlease choose any field to update: \n");
					while(count_of_field_values < count_of_field_names - 1)
					{
						printf("\n%d. %s", ++count_of_field_values, list_of_fields[count_of_field_values + 1]);
					}
					printf("\n\nEnter your choice: ");
					scanf("%d", &choice);
					fflush(stdin);
					if(choice > 0 && choice < count_of_field_names)
					{
						printf("\nEnter %s to update: ", list_of_fields[choice]);
						gets(field_value);
						fseek(fp_data, (long)(long)(-sizeof(field_value)), SEEK_CUR);
						fseek(fp_data, (choice * sizeof(field_value)), SEEK_CUR);		
						fwrite(field_value, sizeof(field_value), 1, fp_data);
						printf("\nRecord updated.\n");		
					}
					break;
				}
			}
		}
	}
	if(record_found == 0)
	{
		printf("\nField not found.\n");
	}
	fclose(fp_data);
}
void delete()
{
	fp_data = fopen(DATABASE_FILE, "r+");
	record_found = 0;
	if (fp_data != NULL)
	{
		printf("\nEnter %s to delete: ", list_of_fields[0]);
		gets(search_value);
		fseek(fp_data, 0, SEEK_SET);
		while(fread(field_value, sizeof(field_value),1, fp_data))
		{
			if(strcmp(active, field_value) == 0)
			{
				fread(field_value, sizeof(field_value),1, fp_data);
				if(strcmp(search_value, field_value) == 0)
				{
					record_found++;
					count_of_field_values = 0;
					fseek(fp_data, (long)(long)(- 2 * sizeof(field_value)), SEEK_CUR);
					fwrite(inactive, sizeof(field_value),1 , fp_data);
					printf("\nRecord deleted.\n");
					break;
				}
			}
		}
	}
	if(record_found == 0)
	{
		printf("\nField not found.\n");
	}
	fclose(fp_data);
}







/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MENU_FILE "menu.cfg"
#define FIELDS_FILE "fields.cfg"
#define DATABASE_FILE "database.dat"
void create();
void display();
void search();
void update();
void delete();
void count_of_fields();
void field_list();
FILE *fp, *fp_field, *fp_data;
char **list_of_fields;
int count_of_field_values = 0, count_of_field_names, record_found = 0;
char menu_line[60], field_name[40], field_value[40], search_value[40];
char active[10] = "active", inactive[10] = "inactive";
void main()
{
	count_of_fields();
	field_list();
	int choice;
	fp = fopen(MENU_FILE, "r");
	while(1)
	{
		while(fgets(menu_line, sizeof(menu_line), fp))
		{	
			printf("\n%s", menu_line);
		}
		scanf("%d", &choice);
		fflush(stdin);
		switch(choice)
		{
			case 1: create();
			break;
			case 2: display();
			break;
			case 3: update();
			break;
			case 4: search();
			break;
			case 5: delete();
			break;
			case 6: exit(0);
			break;
			default: printf("\nInvalid choice.\n");
			break;
		}
		rewind(fp);
	}
	fclose(fp);
}
void count_of_fields()
{
	FILE *fp_count_of_fields;
	fp_count_of_fields = fopen(FIELDS_FILE, "r");
	while(fgets(field_name, sizeof(field_name), fp_count_of_fields))
	{
		count_of_field_values++;	
	}
	count_of_field_names = count_of_field_values;
	//printf("count of field names = %d", count_of_field_names);
	fclose(fp_count_of_fields);
}
void field_list()
{
	fp = fopen(FIELDS_FILE, "r");
	list_of_fields = malloc(count_of_field_names * sizeof(char*));
	count_of_field_values = 0;
	while(fgets(field_name, sizeof(field_name), fp))
	{
		list_of_fields[count_of_field_values] = malloc(count_of_field_names * sizeof(char *));
		strcpy(list_of_fields[count_of_field_values], field_name);
		list_of_fields[count_of_field_values][strlen(list_of_fields[count_of_field_values]) - 1] = '\0';
		count_of_field_values++;
	}
	fclose(fp);
}
void create()
{
	fp_data = fopen(DATABASE_FILE, "a+");
	int no_of_records;
	record_found = 0;
	printf("\nHow many records do you want to create?: ");
	scanf("%d", &no_of_records);
	fflush(stdin);
	for(int record_counter = 0; record_counter < no_of_records; record_counter++)
	{
		count_of_field_values = 0;
		printf("\nEnter record %d\n", record_counter + 1);
		fwrite(active, sizeof(field_value),1, fp_data);
		while(count_of_field_values < count_of_field_names)
		{
			printf("\nEnter %s: ", list_of_fields[count_of_field_values]);
			gets(field_value);
			fwrite(field_value, sizeof(field_value), 1, fp_data);
			count_of_field_values++;
			record_found++;
		}
	}
	if(record_found == 0)
	{
		printf("\nFile does not exist.\n");
	}
	fclose(fp_data);
}
void display()
{
	fp_data = fopen(DATABASE_FILE, "r+");
	record_found = 0;
	if(fp_data != NULL)
	{
		fseek(fp_data, 0, SEEK_SET);
		while(fread(field_value, sizeof(field_value), 1, fp_data))
		{
			if(strcmp(active, field_value) == 0)
			{
				count_of_field_values = 0;
				while(count_of_field_values < count_of_field_names)
				{
					record_found++;
					fread(field_value, sizeof(field_value), 1, fp_data);
					printf("\n%s is: %s\n", list_of_fields[count_of_field_values], field_value);
					count_of_field_values++;
				}
			}
		}
	}
	if(record_found == 0)
	{
		printf("\nFile does not exist.\n\n");
	}
	fclose(fp_data);
}
void search()
{
	fp_data = fopen(DATABASE_FILE, "r");
	printf("\nEnter %s to search: ", list_of_fields[0]);
	gets(search_value);
	while(fread(field_value, sizeof(field_value), 1, fp_data))
	{
		if(strcmp(active, field_value) == 0)
		{
			fread(field_value, sizeof(field_value), 1, fp_data);
			if(strcmp(search_value, field_value) == 0)
			{
				record_found++;
				count_of_field_values = 0;
				while(count_of_field_values < count_of_field_names)
				{
					printf("\n%s is: %s\n", list_of_fields[count_of_field_values], field_value);
					fread(field_value, sizeof(field_value), 1, fp_data);
					count_of_field_values++;
				}
				break;
			}
		}
	}
	fclose(fp_data);
}
void update()
{
	int choice;
	fp_data = fopen(DATABASE_FILE, "r+");
	printf("\nEnter %s to update: ", list_of_fields[0]);
	gets(search_value);
	fseek(fp_data, 0, SEEK_SET);
	while(fread(field_value, sizeof(field_value), 1, fp_data))
	{
		if(strcmp(active, field_value) == 0)
		{
			fread(field_value, sizeof(field_value), 1, fp_data);
			if(strcmp(search_value, field_value) == 0)
			{
				record_found++;
				count_of_field_values = 0;
				printf("\nplease select any field to update: \n");
				while(count_of_field_values < count_of_field_names)
				{
					printf("\n%d. %s\n", ++count_of_field_values, list_of_fields[count_of_field_values]);
				}
				printf("\nEnter your choice: ");
				scanf("%d", &choice);
				fflush(stdin);
				if(choice > 0 && choice < count_of_field_values)
				{
					printf("\nEnter %s to update: ", list_of_fields[choice - 1]);
					gets(field_value);
					fseek(fp_data, (long)(long)(-sizeof(field_value)), SEEK_CUR);
					fseek(fp_data, (choice -1)*(sizeof(field_value)), SEEK_CUR);
					fwrite(field_value, sizeof(field_value), 1, fp_data);
					printf("\nUpdated succesfully\n");
				}
				break;

			}
		}
	}
	if(record_found == 0)
	{
		printf("\nField not found\n");
	}
	fclose(fp_data);
}
void delete()
{
	fp_data = fopen(DATABASE_FILE, "r+");
	printf("\nEnter %s to delete: ", list_of_fields[0]);
	gets(search_value);
	fseek(fp_data, 0, SEEK_SET);
	while(fread(field_value, sizeof(field_value), 1, fp_data))
	{
		if(strcmp(active, field_value) == 0)
		{
			fread(field_value, sizeof(field_value), 1, fp_data);
			if(strcmp(search_value, field_value) == 0)
			{
				record_found++;
				fseek(fp_data, (long)(long)(-2 * sizeof(field_value)), SEEK_CUR);
				fwrite(inactive, sizeof(field_value), 1, fp_data);
				printf("\nRecord deleted\n");
			}
		}
	}
	if(record_found == 0)
	{
		printf("\nField not found\n");
	}
	fclose(fp_data);
}*/