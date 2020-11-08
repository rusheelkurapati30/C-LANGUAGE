
// CRUD operations.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>	
#define  DATA_FILE "employee.dat"
struct crud
{
	int emp_id;
	char emp_name[40];
	float emp_salary;
	char status;
};
struct crud employee_details;
int record_found = 0;
void show_menu();
void display();
void update_data();
void print_record();
void modify_data();
void create();
void read();
void update();
void delete();
void search();
void exit();
void main()
{
	while(1)
	{
		show_menu();
	}
}
void show_menu()
{
	int choice;
	printf("------------- EMPLOYEE RECORD MANAGEMENT -------------\n");
	printf("Please choose: \n1. New employee\n2. Show all employees\n3. Update an employee\n4. Delete an employee\n5. Search an employee\n6. exit\n");
	printf("-------------------------------------------------------\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1: create();
		break;
		case 2 : read();
		break;
		case 3 : update();
		break;
		case 4 : delete();
		break;
		case 5 : search();
		break;
		case 6 : exit(0);
		break;
		default :
		printf("Error! Wrong Number is Entered, Please Try Again\n");
	}
}
void create()
{
	FILE *fp_create;
	fp_create = fopen(DATA_FILE, "a");
	if(fp_create == NULL)
	{
		printf("File does not exist");
		exit(0);
	}
	int no_of_employees;
	printf("\nHow many employee details you want to create: ");
	scanf("%d", &no_of_employees);
	fflush(stdin);
	for(int emp_member = 0; emp_member < no_of_employees; emp_member++)	
	{
		printf("\nEnter employee %d details: \n", emp_member + 1);
		printf("Enter employee ID: ");
		scanf("%d", &employee_details.emp_id);
		fflush(stdin);
		printf("Enter employee Name: ");
		gets(employee_details.emp_name);
		printf("Enter employee Salary: ");
		scanf("%f", &employee_details.emp_salary);
		employee_details.status = 'A';
		fwrite(&employee_details, sizeof(employee_details), 1, fp_create);
		if(emp_member == no_of_employees - 1)
		{
			printf("\nEmployee Records Added Succesfully.\n\n");
			break;
		}
	}
	fclose(fp_create);
}
void read()
{
	display(0);
}
void search()
{
	display(1);
}
void display(int read_mode)
{
	FILE *file_ptr;
	file_ptr = fopen(DATA_FILE, "r");
	if(file_ptr == NULL)
	{
		printf("\nFile does not exist\n\n");
		show_menu();
	}
	if(read_mode == 0)
	{
		record_found = 0;
		while(fread(&employee_details, sizeof(employee_details), 1, file_ptr))
		{	
			print_record();
		}
		fclose(file_ptr);
	}
	else
	{	
		int search_id_number;  
		printf("\nEnter the employee ID you want to search: ");
		scanf("%d", &search_id_number);
		if(search_id_number == 0)
		{
			printf("Employee ID %d is not available in the file.\n", search_id_number);
		}
		while(fread(&employee_details, sizeof(employee_details), 1, file_ptr))
		{
			if(employee_details.emp_id == search_id_number)
			{
				print_record();
				//record_found++;
				break;
			}
			if(record_found == 0)
			{
				printf("\nInvalid ID\n");
				break;
		    }
		}
		fclose(file_ptr);
	}
}
void print_record()
{
	if(employee_details.status == 'A')
	{
		record_found++;
		if(record_found == 1)
		{
			printf("\n%5s%25s%20s\n", "Employee ID", "Employee Name", "Employee Salary");	
		}
		printf("\n%5d%25s%20.2f\n", employee_details.emp_id, employee_details.emp_name, employee_details.emp_salary);
	}
}
void update()
{
	modify_data("update");
}
void delete()
{
	modify_data("delete");
}
void modify_data(char mode[])
{
	FILE *fp_modify;
	int id, select;
	record_found = 0;
	printf("\nEnter the employee ID you want to %s: ", mode);
	scanf("%d", &id);
	fp_modify = fopen(DATA_FILE, "r+");
	while(fread(&employee_details, sizeof(employee_details), 1, fp_modify))
	{
		if(employee_details.emp_id == id)
		{
			record_found++;
			if(strcmp(mode, "update") == 0)
			{
				printf("\n1. Update Name of the Employee ID %d", id);
				printf("\n2. Update Salary of the Employee ID %d", id);
				printf("\n3. Update both Name and Salary of Employee ID %d\n", id);
				printf("\nEnter your choice: ");
				scanf("%d", &select);
			    fflush(stdin);
				switch (select)
				{
					case 1:
					printf("\nEnter employee name: ");
					gets(employee_details.emp_name);
					update_data(fp_modify);
					break;
					case 2:
					printf("\nEnter employee salary: ");
					scanf("%f", &employee_details.emp_salary);
					update_data(fp_modify);
					fflush(stdin);
					break;
					case 3:
					printf("\nEnter employee name: ");
					gets(employee_details.emp_name);
					printf("\nEnter employee salary: ");
					scanf("%f", &employee_details.emp_salary);
					update_data(fp_modify);
					break;
					default:
					printf("\nInvalid Selection\n");
					break;
				}
				break;
			}
			else if(strcmp(mode, "delete") == 0)
			{
				employee_details.status = 'D';
				fseek(fp_modify, (long long)(-sizeof(struct crud)), SEEK_CUR);
				fwrite(&employee_details, sizeof(employee_details), 1, fp_modify);
				record_found++;
				printf("\nRecord Deleted\n");
				break;	
			}
		}
	}	
	if(record_found == 0)
	{
		printf("\nInvalid ID\n");
	}
	fclose(fp_modify);
}
void update_data(FILE *fp_modify)
{
	fseek(fp_modify, (long long)(-sizeof(struct crud)), SEEK_CUR);
	fwrite(&employee_details, sizeof(employee_details), 1, fp_modify);
	printf("\n Record Updated\n");
}