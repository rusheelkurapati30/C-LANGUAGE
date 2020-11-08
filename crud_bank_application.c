
// BANK APPLICATION

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BANK_FILE "bank_data.dat"
struct bank
{
	long long acc_number;
	char bank_name[30];
	char branch_name[20];
	char acc_holder_name[30];
	char acc_holder_address[80];
	char status;
	float balance;
};
struct bank customer_accounts;
int record_found = 0;
void show_menu();
void print_record();
void update_data();
void modify_account();
void balance();
void create();
void deposit();
void withdrawl();
void read();
void update();
void delete();
void display();
void search();
void main()
{
	//show_menu();
	while(1)
	{
		show_menu();
	}
}
void show_menu()
{
	int choice;
	printf("\n******* Welcome to Bank Application *******\n");
	printf("\nPlease choose: \n1. New account\n2. Display all accounts\n3. Cash deposit\n4. Cash withdrawl\n5. Update an account\n6. Searh an account\n7. Delete an account\n8. Exit\n");
	printf("\n*******************************************\n");
	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1: create();
		break;  
		case 2: read();
		break;
		case 3: deposit();
		break;
		case 4: withdrawl();
		break;
		case 5: update();
		break;
		case 6: search();
		break;
		case 7: delete();
		break;
		case 8: exit(0);
		break;
		default:
		printf("\nError! Wrong Number is Entered, Please Try Again\n");
	}
}
void create()
{
	FILE *fp;
	fp = fopen(BANK_FILE, "a");
	if(fp == NULL)
	{
		printf("File does not exist");
		exit(0);
	}
	int no_of_accounts;
	printf("\nHow many customer accounts do you want to create? : ");
	scanf("%d", &no_of_accounts);
	for(int account = 0; account < no_of_accounts; account++)
	{
		printf("\nEnter customer account %d: ", account+1);
		printf("\n\nEnter the account number: ");
		scanf("%lld", &customer_accounts.acc_number);
		fflush(stdin);
		printf("\nEnter the bank name: ");
		gets(customer_accounts.bank_name);
		printf("\nEnter the branch name: ");
		gets(customer_accounts.branch_name);
		printf("\nEnter the account holder name: ");
		gets(customer_accounts.acc_holder_name);
		printf("\nEnter the account holder address: ");
		gets(customer_accounts.acc_holder_address);
		customer_accounts.status = 'A';
		customer_accounts.balance = 0;
		fwrite(&customer_accounts, sizeof(customer_accounts), 1, fp);
		if(account == no_of_accounts - 1)
		{
			printf("\nAccount has been created succesfully\n");
			break;
		}
	}
	fclose(fp);
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
	FILE *fp;
	fp = fopen(BANK_FILE, "r+");
	if(fp == NULL)
	{
		printf("\nFile does not exist\n\n");
	}
	if(read_mode == 0)
	{
		record_found = 0;
		while(fread(&customer_accounts, sizeof(customer_accounts), 1, fp))
		{
			print_record();
		}
		fclose(fp);
	}
	else
	{
		long long search_account;  
		printf("\nEnter the customer account number you want to search: ");
		scanf("%lld", &search_account);
		while(fread(&customer_accounts, sizeof(customer_accounts), 1, fp))
		{
			if(customer_accounts.acc_number == search_account)
			{
				record_found = 0;
				print_record();
				break;
			}
			if(record_found == 0)
			{
				printf("\nInvalid Account Number\n");
				break;
		    }
		}
		fclose(fp);
	}
}
void print_record()
{
	if(customer_accounts.status == 'A')
	{
		record_found++;
		if(record_found == 1)
		{
			printf("\n%15s%20s%15s%20s%25s%15s\n\n", "Name", "Bank Name", "Branch Name", "Account Number", "Address", "balance");
		}
		printf("\n%15s%20s%15s%20lld%25s%15.2f\n\n", customer_accounts.acc_holder_name, customer_accounts.bank_name, customer_accounts.branch_name, customer_accounts.acc_number, customer_accounts.acc_holder_address, customer_accounts.balance);
	}
}
void update()
{
	modify_account("update");
}
void delete()
{
	modify_account("delete");
}
void deposit()
{
	modify_account("deposit");
}
void withdrawl()
{
	modify_account("withdrawal");
}
void modify_account(char mode[])
{
	FILE *fp;
	fp = fopen(BANK_FILE, "r+");
	long long acc_no, select;int record_found = 0; float amount;
	printf("\nEnter the customer account number you want to %s: ", mode);
	scanf("%lld", &acc_no);
	while(fread(&customer_accounts, sizeof(customer_accounts), 1, fp))
	{
		if(customer_accounts.acc_number == acc_no)
		{
			record_found++;
			if(strcmp(mode, "update") == 0)
			{
				printf("\n1. Update Name of the account holder.\n");
				printf("2. Update Address of the account holder.\n");
				printf("3. Update both name and address of the account holder.\n");
				printf("\nEnter your choice: ");
				scanf("%d", &select);
				fflush(stdin);
				switch(select)
				{
					case 1:
					printf("\nEnter name of the account holder: ");
					gets(customer_accounts.acc_holder_name);
					update_data(fp);
					break;
					case 2:
					printf("\nEnter address of the account holder: ");
					gets(customer_accounts.acc_holder_address);
					update_data(fp);
					break;
					case 3:
					printf("\nEnter name of the account holder: ");
					gets(customer_accounts.acc_holder_name);
					update_data(fp);
					break;
					case 4:
					printf("\nEnter address of the account holder: ");
					gets(customer_accounts.acc_holder_address);
					update_data(fp);
					break;
					default:
					printf("\nInvalid Selection\n");
					break;
				}
			}
			else if(strcmp(mode, "delete") == 0)
			{
				customer_accounts.status = 'D';
				fseek(fp, (long long)(-sizeof(struct bank)), SEEK_CUR);
				fwrite(&customer_accounts, sizeof(customer_accounts), 1, fp);
				printf("\nRecord Deleted\n");
				break;	
			}
			else if(strcmp(mode, "deposit") == 0)
			{
				printf("\nHow much amount do you want to deposit?: ");
				scanf("%f", &amount);
				customer_accounts.balance = customer_accounts.balance + amount;
				update_data(fp);
				break;
			}	
			else if(strcmp(mode, "withdrawal") == 0)
			{
				printf("\nHow much amount do you want to withdrawal?: ");
				scanf("%f", &amount);
				if(customer_accounts.balance >= amount)
				{
					customer_accounts.balance = customer_accounts.balance - amount;
					update_data(fp);
					break;
				}
				else
				{
					printf("\nInsufficient balance\n");
				}
				break;
			}
		}
	}	
	if(record_found == 0)
	{
		printf("\nInvalid Account number\n");
	}
	fclose(fp);
}
void update_data(FILE *fp)
{
	fseek(fp, (long long)(-sizeof(struct bank)), SEEK_CUR);
	fwrite(&customer_accounts, sizeof(customer_accounts), 1, fp);
	printf("\nAccount Updated\n");
}
































/*void load_fields()
{
	fp = fopen(FIELDS_FILE , "r");
	fields_ptr = malloc(count_of_field_names * sizeof(char*));
	while(fgets(field_name, sizeof(field_name), fp))
	{
		fields_ptr[counter] = malloc(100);
		strcpy(fields_ptr[counter], field_name);
		counter++;
	}
	fclose(fp);
}*/
/*void load_fields()
{
	fp = fopen(FIELDS_FILE , "r");
	int counter = 0;
	fields_ptr = malloc(count_of_field_names * sizeof(char*));
	while(fgets(field_name, sizeof(field_name), fp))
	{
		fields_ptr[counter] = malloc(sizeof(char) * 100);
		strcpy(fields_ptr[counter], field_name);
		counter++;
	}
	fclose(fp);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MENU_FILE "menu.cfg"
#define FIELDS_FILE "fields.cfg"
#define DATA_FILE "database.dat"
void create();
void display();
void count_fields();
void load_fields();
int count_of_field_names;
void main()
{
	count_fields();
	FILE *fp;
	int choice;
	char menu_line[50];
	fp = fopen(MENU_FILE, "r");
	if(fp != NULL)
	{
		while(1)
		{
			while(fgets(menu_line, sizeof(menu_line), fp))
			{
				printf("\n");
				printf("%s", menu_line);
			}
			scanf("%d", &choice);
			fflush(stdin);
			switch(choice)
			{
				case 1: create();
				break;
				case 2: display();
				break;
				case 3: exit(0);
				break;
				default:
				printf("\nInvalid choice\n\n");
			}
			rewind(fp);
		}
		fclose(fp);
	}
	else
	{
		printf("File not found.");
	}
}
void count_fields()
{
	FILE *fp;
	char field_name[40];
	int counter = 1;
	fp = fopen(FIELDS_FILE, "r");
	while(fgets(field_name, sizeof(field_name), fp))
	{
		counter++;
	}	
	count_of_field_names = counter;
	printf("\nCount of field names =  %d\n", count_of_field_names);
	rewind(fp);
}
void create()
{
	FILE *fp_field, *fp_data;
	char field_name[40], field_value[40];
	fp_field = fopen(FIELDS_FILE, "r");
	if(fp_field != NULL)
	{
		fp_data = fopen(DATA_FILE, "a");
		int counter = 1;
		while(fgets(field_name, sizeof(field_name), fp_field))
		{
			if(counter < count_of_field_names-1)
			{
				field_name[strlen(field_name) - 1] = ':';
				printf("\nEnter %s ", field_name);
				gets(field_value);
				fwrite(field_value, sizeof(field_value), 1, fp_data);
			}
			counter++;
		}
		fclose(fp_field);
		fclose(fp_data);
	}
}
void display()
{
	FILE *fp_field, *fp_data;
	char field_name[40], field_value[40];
	fp_field = fopen(FIELDS_FILE, "r");
	fp_data = fopen(DATA_FILE, "r");
	if(fp_field != NULL && fp_data != NULL)
	{
		while(fgets(field_name, sizeof(field_name), fp_field) && (fread(field_value, sizeof(field_value), 1, fp_data)))
		{
			field_name[strlen(field_name) - 1] = ' ';
			printf("\n%sis: %s\n", field_name, field_value);
		}
		fclose(fp_data);
		fclose(fp_field);
	}
	else
	{
		printf("\nFile does not exist\n\n");
	}
}*/










