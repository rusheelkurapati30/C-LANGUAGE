//ADD two numbers.

/*#include<stdio.h>
void main()
{
	int number1, number2, sum = 0;
	printf("\nEnter two numbers: ");
	scanf("%d", &number1);
	scanf("%d", &number2);
	sum = number1 + number2;
	printf("\nSum of %d and %d is: %d", number1, number2, sum);

}*/

//Print n natural numbers.

/*#include<stdio.h>
void main()
{
	int noOfNaturalNo, naturalNumber = 1;
	printf("How many natural numbers do you want?: ");
	scanf("%d", &noOfNaturalNo);
	for(int ctr_marks = 1; ctr_marks <= noOfNaturalNo; ctr_marks++)
	{
		//if(ctr_marks)
		printf("%2d\n", ctr_marks);
	}
}*/


// Multiply three numbers.

/*#include<stdio.h>
void main()
{
	int number1, number2, number3, product;
	printf("\nEnter any three numbers: ");
	scanf("%d %d %d", &number1, &number2, &number3);
	product = number1*number2*number3;
	printf("\nProduct of %d, %d and %d is: %d", number1, number2, number3, product);
}*/


// Print n even numbers.

/*#include<stdio.h>
void main()
{
	int evenNumber = 2, noOfEvenNumbers;
	printf("\nHow many even numbers do you want?: ");
	scanf("%d", &noOfEvenNumbers);
	for(int ctr_marks = 1; ctr_marks <= noOfEvenNumbers; ctr_marks++)
	{
		printf("%d\n", evenNumber);
		evenNumber = evenNumber + 2;
	}
}*/

// Print n odd numbers.

/*#include<stdio.h>
void main()
{
	int oddNumber = 1, noOfOddNumbers;
	printf("\nHow many odd numbers do you want?: ");
	scanf("%d", &noOfOddNumbers);
	for(int ctr_marks = 1; ctr_marks <= noOfOddNumbers; ctr_marks++)
	{
		printf("%d\n", oddNumber);
		oddNumber = oddNumber + 2;
	}
}
*/


// Print sum of n natural numbers.

/*#include<stdio.h>
void main()
{
	int sum = 0, noOfNaturalNo, naturalNumber = 1;
	printf("\nHow many natural numbers do to you want to sum? ");
	scanf("%d", &noOfNaturalNo);
	for(int ctr_marks = 1; ctr_marks <= noOfNaturalNo; ctr_marks++)
	{
		sum = sum + ctr_marks;
	}
	printf("Sum of %d natural numbers is: %d", noOfNaturalNo, sum);

}
*/


//	Sum of cubes of n odd numbers.

/*#include<stdio.h>
void main()
{
	int sumOfCubes = 0, oddNumber = 1, product, noOfOddNumbers;
	printf("\nHow many cubes of odd numbers do you want to sum? ");
	scanf("%d", &noOfOddNumbers);
	for(int ctr_marks = 1; ctr_marks <= noOfOddNumbers; ctr_marks++)
	{
		product = oddNumber * oddNumber * oddNumber;
		sumOfCubes = sumOfCubes + product;
		oddNumber += 2;
	}
	printf("\nSum of cubes of %d odd numbers is: %d",noOfOddNumbers, sumOfCubes);
}*/


//Print multiplication of a given table.

/*#include<stdio.h>
void main()
{
	int tableNumber;
	printf("\nEnter which multiplication table number you want to print: ");
	printf("\nMultiplication table of %d is: ", tableNumber);
	for(int ctr_marks = 1; ctr_marks <= 10; ctr_marks++)
	{
		printf("\n%3d x %3d = %3d", tableNumber, ctr_marks, tableNumber*ctr_marks);
	}
}*/

// Print n to the power of n.

/*#include<stdio.h>
void main()
{
	int noForBaseAndPower, product;
	printf("\nEnter the value of base and power: ");
	scanf("%d", &noForBaseAndPower);
	product = noForBaseAndPower;
	for(int ctr_marks = 1; ctr_marks < noForBaseAndPower; ctr_marks++)
	{
		product = product * noForBaseAndPower;
	}
	printf("\n%d to the power of %d is: %d", noForBaseAndPower, noForBaseAndPower, product);
}*/

// Print m to the power of n.

/*#include<stdio.h>
void main()
{
	int base, power, product;
	printf("\nEnter base and power: ");
	scanf("%d %d", &base, &power);
	product = base;
	for(int ctr_marks = 1; ctr_marks < power; ctr_marks++)
	{
		product = product * base;
	}
	printf("\n%d to the power of %d is: %d", base, power, product);
}*/

// Print tables book.

/*#include<stdio.h>
void main()
{
	int tableNumber = 1, noOfTableNumbers;
	printf("\nHow many tables you want to print: ");
	scanf("%d", &noOfTableNumbers);
	for(int tablecounter = 1; tablecounter <= noOfTableNumbers; tablecounter++)
	{
		printf("\n\nThe multiplication table of %d is: \n", tableNumber);
		for(int ctr_marks = 1; ctr_marks <= 10; ctr_marks++)
		{
			printf("\n%3d x %3d = %3d\n", tableNumber, ctr_marks, tableNumber*ctr_marks);
		}
		tableNumber++;
	}
}*/

// Print the series 1, 4, 27, .... upto n terms.

/*#include<stdio.h>
void main()
{
	int noOfTerms, product;
	printf("\nPrint the series 1, 4, 27, .... upto n terms.\n");
	printf("\nHow many terms do you want to print?: ");
	scanf("%d", &noOfTerms);
	for(int termcounter = 1; termcounter <= noOfTerms; termcounter++)
	{
		product = 1;
		for(int ctr_marks = 1; ctr_marks <= termcounter; ctr_marks++)
		{
			product = product * termcounter;
			if(termcounter == ctr_marks)
			{
				printf("%d", product);
			}
		}
		if(termcounter < noOfTerms)
		{
			printf(", ");
		}
		else
		{
			printf(".");
		}
	} 
}*/

// Print whether a given number is prime or not.

/*#include<stdio.h>
#include<math.h>
#include<string.h>
void main()
{
	int isPrime = 1, givenNumber, factorCounter;
	printf("\nEnter any number to check whether a given number is prime or not: ");
	scanf("%d", &givenNumber);
	if(givenNumber <= 1)
	{
		isPrime = 0;
	}
	else if(givenNumber != 2)
	{
		if(givenNumber % 2 ==0)
		{
			isPrime = 0;
		}
	}
	else
	{
		int squareRootOfNo = sqrt(givenNumber);
		for(int factorCounter = 3; factorCounter <= squareRootOfNo; factorCounter+= 2)
		{
			if(givenNumber % factorCounter == 0)
			{
				isPrime = 0;
			}
		}
	}
	if(isPrime == 0)
	{
		printf("\n%d is not a prime number.", givenNumber);
	}
	else
	{
		printf("\n%d is a prime number.", givenNumber);
	}
}*/

// Read and print 5 marks.

/*#include<stdio.h>
#include<stdlib.h>
#define NO_OF_MARKS 5
void main()
{	
	int marks[NO_OF_MARKS], ctr_marks;
	for(ctr_marks = 1; ctr_marks <= NO_OF_MARKS; ctr_marks++)
	{
		printf("\nEnter %d mark: ", ctr_marks);
		scanf("%d", &marks[ctr_marks]);
	}
	for(ctr_marks = 1; ctr_marks <= NO_OF_MARKS; ctr_marks++)
	{
		printf("\nMark %d: %d", ctr_marks, marks[ctr_marks]);
	}
}*/

// Read and print 5 names.

/*#include<stdio.h>
#define NO_OF_NAMES 5
#define NO_OF_CHAR 25
void main()
{
	char names[NO_OF_NAMES][NO_OF_CHAR],ctr_marks;
	printf("Enter %d names: \n", NO_OF_NAMES);
	for(ctr_marks = 0; ctr_marks < NO_OF_NAMES; ctr_marks++)
	{
		scanf("%24s", names[ctr_marks]);
	}
	printf("Displaying %d names: \n", NO_OF_NAMES);
	for(ctr_marks = 0; ctr_marks < NO_OF_NAMES; ctr_marks++)
	{
		printf("%s\n", names[ctr_marks]);
	}
}*/

// Read and print n ptr_marks using pointers and malloc().

/*#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *ptr_marks, no_of_marks, ctr_marks;
	printf("\nhow many ptr_marks do you want to print? ");
	scanf("%d", &no_of_marks);
	ptr_marks = (int*)malloc(no_of_marks*sizeof(int));
	printf("%d", ptr_marks);
	if(ptr_marks == NULL)
	{
		printf("Memory cannot be allocated.");
	}
	printf("\nEnter %d ptr_marks: ", no_of_marks);
	for(ctr_marks = 0; ctr_marks < no_of_marks; ctr_marks++)
	{
		scanf("%d", &ptr_marks[ctr_marks]);
		//scanf("%d", ptr_marks+ctr_marks);
	}
	printf("\nDisplaying %d ptr_marks: ", no_of_marks);
	for(ctr_marks = 0; ctr_marks < no_of_marks; ctr_marks++)
	{
		printf("\n%d", ptr_marks[ctr_marks]);
		//printf("%d\n", *(ptr_marks+ctr_marks));
	}

}*/

// Read and print n names using pointers and malloc().

/*#include<stdio.h>
#include<stdlib.h>
void main()
{
	char *ptr_name;
	int ctr_names, no_of_names, no_of_chars;
	printf("\nHow many names do you want to print? ");
	scanf("%d", &no_of_names);
	printf("\nHow many characters do you want to print? ");
	scanf("%d", &no_of_chars);
	ptr_name = (char*)malloc(no_of_names*no_of_chars*sizeof(char));
	printf("\nEnter %d names: ", no_of_names);
	for(ctr_names = 0; ctr_names < no_of_names*no_of_chars; ctr_names+=no_of_chars)
	{
		scanf("%s", ptr_name + ctr_names);
	}
	printf("\nDiaplaying %d names: ", no_of_names);
	for(ctr_names = 0; ctr_names < no_of_names*no_of_chars; ctr_names+=no_of_chars)
	{
		printf("\n%s", ptr_name + ctr_names);
	}*/

	/*int no_of_names, no_of_chars,  ctr_name;
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
	}*/
//}		

// Read a name and save it into a file.

/*#include<stdio.h>
#include<stdlib.h>
void main()
{
	FILE *fp_name;
	char given_name[50];
	fp_name = fopen("file.txt", "a");
	if(fp_name == NULL)
	{
		printf("\nFile does not exist.\n");
	}
	printf("\nEnter a name: ");
	scanf("%s", given_name);
	fprintf(fp_name, "Name: %s", given_name);
	fclose(fp_name);
}
*/

// Read all the names from the file.

/*#include<stdio.h>
void main()
{
	FILE *fp_name;
	char read_name[50];
	fp_name = fopen("file.txt", "r");
	if(fp_name == NULL)
	{
		printf("\nFile does not exist.\n");
	}
	while(fgets(read_name, sizeof(read_name), fp_name))
	{
		printf("%s", read_name);
	}
}*/

// Read account details and print them using structures.

/*#include<stdio.h>
struct account_details
{
	char account_number[25];
	char account_holder_name[25];
}account;
void main()
{
	printf("\nEnter account number: ");
	gets(account.account_number);
	printf("\nEnter account holder name: ");
	gets(account.account_holder_name);
	printf("\nDisplaying account details: \n");
	printf("\nAccount number: %s", account.account_number);
	printf("\naccount holder name: %s\n", account.account_holder_name);
}*/

// Read account details and save it into a file using structures and fwrite().

/*#include<stdio.h>
struct account_details
{
	char account_number[25];
	char account_holder_name[25];
};
void main()
{
	struct account_details bank_account;
	FILE *fp_account_details;
	fp_account_details = fopen("bank_details.dat", "a");
	if(fp_account_details == NULL)
	{
		printf("\nFile does not exist.\n");
	}
	printf("\nEnter account number: ");
	gets(bank_account.account_number);
	printf("\nEnter account holder name: ");
	gets(bank_account.account_holder_name);
	fwrite(&bank_account, sizeof(bank_account),1, fp_account_details);
	fclose(fp_account_details);
}
*/

// Read all the account details from the file and print it.

/*#include<stdio.h>
struct account_details
{
	char account_number[25];
	char account_holder_name[25];
};
void main()
{
	struct account_details bank;
	FILE *fp_account_details;
	fp_account_details = fopen("bank_details.dat", "r");
	if(fp_account_details == NULL)
	{
		printf("\nFile dose not exist.\n");
	}
	while(fread(&bank, sizeof(bank),1 ,fp_account_details))
	{
		printf("\nAccount number: %s", bank.account_number);
		printf("\nAccount holder name: %s", bank.account_holder_name);
	}
	fclose(fp_account_details);
}*/

// Write a function and call it from main().

/*#include<stdio.h>
int total;
int add(int number1, int number2)
{
	total = number1 + number2;
	return total;
}
void main()
{
	int number1, number2;
	printf("\nEnter number1 and number2: ");
	scanf("%d %d", &number1, &number2);
	total = add(number1, number2);
	printf("%d + %d = %d", number1, number2, total);

}*/

/*#include<stdio.h>
#include<string.h>
char input_name[20];
char name(char input_name[])
{
	if(strcmp(input_name, "rusheel") == 0)
	{
		printf("Correct\n");
	}
	else
	{
		printf("\nwrong");
	}
}
void main()
{
	printf("\nEnter a name: ");
	scanf("%s", input_name);
	name(input_name);
	//printf("\nInput name is: %s", input_name);
}*/

// Print all command line arguments.

/*#include<stdio.h>
void main(int argcount, char *arglist[])
{
	if(argcount == 1)
	{
		printf("\nNo command line arguments are passed.\n");
	}
	for(int counter = 1; counter <= argcount; counter++)
	{
		printf("%s\n", arglist[counter]);
	}
}*/
 

// Print sum of all command line arguments.

/*#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void main(int argcount, char *arglist[])
{
	int counter, sum =0;
	if(argcount == 1)
	{
		int max_numbers;
		printf("\nHow many numbers do you want to add? press 0 to exit.");
		scanf("%d", &max_numbers);
		if(max_numbers == 0)
		{
			exit(0);
		}
		while(max_numbers < 2)
		{
			printf("\nEnter minimum 2 numbers to add: \n");
			scanf("%d", &max_numbers);
		}
		int number[max_numbers];
		printf("\nEnter %d numbers: \n", max_numbers);
		for(counter = 0; counter < max_numbers; counter++)
		{
			scanf("%d", &number[counter]);
		}
		for(counter = 0; counter < max_numbers; counter++)
		{
			sum = sum + number[counter];
		}
		printf("The sum of %d numbers is: %d", max_numbers, sum);
		exit(0);
	}
	if(argcount > 1)
	{
		for(counter = 1; counter < argcount; counter++)
		{
			if(isdigit(*arglist[counter]) == 0)
			{
				printf("%s is not a number, please use valid number.\n", arglist[counter]);
				exit(0);
			}
		}
	}
	if(argcount > 2)
	{
		int sum = 0;
		for(counter = 1; counter < argcount; counter++)
		{
			sum = sum + atoi(arglist[counter]);
		}
		if(sum > 0)
		{
			printf("The sum of %d numbers is: %d\n", argcount-1, sum);
		}
	}
}*/

// Add two numbers by passing command line arguments

/*#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void main(int argcount, char *arglist[])
{
	int sum = 0;
	if(argcount == 1)
	{
		printf("\nNo command line arguments ard passed\n");
	}
	if(argcount > 1)
	{
		for(int counter = 1; counter < argcount; counter++)
		{
			if(isdigit(*arglist[counter]) == 0)
			{
				printf("%s is not a number, please enter a valid number.\n", arglist[counter]);
			}
		}
	}
	if(argcount > 2)
	{
		for(int counter = 1; counter < argcount; counter++)
		{
			sum = sum + atoi(arglist[counter]);
		}
		printf("The sum of %d and %d is: %d", atoi(arglist[1]), atoi(arglist[2]), sum);
	}
}
*/

// Print given names given number of times.

/*#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
void main(int argcount, char *arglist[])
{
	if(argcount == 3)
	{
		printf("\nThe output is: \n");
		for(int counter = 0; counter < atoi(arglist[2]); counter++)
		{
			printf("%s\n", arglist[1]);
		}
	}
	else
	{
		printf("\nInvalid arguments, please use <name> <count of names>");
	}
}*/

//CRUD opeartions Employee domain.

/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DATA_FILE "employee1.dat"
struct employee_fields
{
	int emp_id;
	char emp_name[40];
	float emp_salary;
	char status;
};
struct employee_fields employee;
FILE *fp;
int choice, record_found = 0;
void show_menu();
void create();
void read();
void search();
void display();
void print_record();
void update();
void update_data();
void delete();
void modify_date();
void main()
{
	while(1)
	{
		show_menu();
	}
}
void show_menu()
{
	printf("\n********** EMPLOYEE MANAGEMENT SYSTEM **********\n");
	printf("\nPlease choose:\n");
	printf("\n1. New employee.\n2. Display employee details.\n3. Update an employee.\n4. Search an employee.\n5. Delete an employee.\n6. exit.\n");
	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1: create();
		break;
		case 2: read();
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
		printf("\nInvalid choice! Please Try Again\n");
		break;
	}
}
void create()
{
	fp = fopen(DATA_FILE, "a");
	int no_of_employees, emp_member;
	printf("\nHow many employee records you want to create: ");
	scanf("%d", &no_of_employees);
	fflush(stdin);
	for(emp_member = 1; emp_member <= no_of_employees; emp_member++)
	{
		printf("\nEnter employee %d details: \n", emp_member);
		printf("Enter employee ID: ");
		scanf("%d", &employee.emp_id);
		fflush(stdin);
		printf("Enter employee Name: ");
		gets(employee.emp_name);
		printf("Enter employee Salary: ");
		scanf("%f", &employee.emp_salary);
		employee.status = 'A';
		fwrite(&employee, sizeof(employee), 1, fp);
		if(emp_member == no_of_employees)
		{
			printf("\nEmployees Records Added succesfully\n");
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
	fp = fopen(DATA_FILE, "r");
	if(fp == NULL)
	{
		printf("\nFile does not exist.\n");
		show_menu();
	}
	if(read_mode == 0)
	{
		record_found = 0;
		while(fread(&employee, sizeof(employee), 1, fp))
		{
			print_record();
		}
		fclose(fp);
	}
	else
	{
		int search_id_number;
		printf("\nEnter employee ID to search: ");
		scanf("%d", &search_id_number);
		if(search_id_number == 0)
		{
			printf("\nEmployee ID %d is not available in the file.\n", search_id_number);
		}
		while(fread(&employee, sizeof(employee), 1, fp))
		{
			if(employee.emp_id == search_id_number)
			{
				print_record();
				break;
			}
			if(record_found == 0)
			{
				printf("\nInvalid ID.\n");
				break;
			}
		}
		fclose(fp);	
	}
}
void print_record()
{
	if(employee.status == 'A')
	{
		record_found++;
		if(record_found == 1)
		{
			printf("\n%5s%25s%20s\n", "Employee ID", "Employee Name", "Employee Salary");
		}
		printf("\n%5d%25s%20.2f\n", employee.emp_id, employee.emp_name, employee.emp_salary);
	}
}
void update()
{
	modify_date("update");
}
void delete()
{
	modify_date("delete");
}
void modify_date(char mode[])
{
	int id, select;
	fp = fopen(DATA_FILE, "r+");
	printf("\nEnter the employee ID you want to %s: ", mode);
	scanf("%d", &id);
	while(fread(&employee, sizeof(employee), 1, fp))
	{
		if(employee.emp_id == id)
		{
			record_found++;
			if(strcmp(mode, "update") == 0)
			{
				printf("\n1. Update Name of the Employee ID %d", id);
				printf("\n2. Update Salary of the Employee ID %d\n", id);
				printf("\nEnter your choice: ");
				scanf("%d", &select);
			    fflush(stdin);
				switch (select)
				{	
					case 1:
					printf("\nUpdate employee name: ");
					gets(employee.emp_name);
					update_data(fp);
					break;
					case 2:
					printf("\nUpdate employee salary: ");
					scanf("%f",&employee.emp_salary);
					fflush(stdin);
					update_data(fp);
					break;
				}
				break;
			}
			else
			{
				employee.status = 'D';
				fseek(fp, (long)(long)(-sizeof(employee)), SEEK_CUR);
				fwrite(&employee, sizeof(employee), 1, fp);
				printf("\nDeleted sucessfully.\n");
				break;
			}
		}
	}
	if(record_found == 0)
	{
		printf("\nInvalid ID.\n");
	}
	fclose(fp);
}
void update_data(FILE *fp)
{
	fseek(fp, (long)(long)(-sizeof(employee)), SEEK_CUR);
	fwrite(&employee, sizeof(employee), 1, fp);
	printf("\nUpdated sucessfully.\n");
}*/


//CRUD OPERATIONS BANK DOMAIN.

/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BANK_DATA_FILE "bank_data.dat"
struct account_fields 
{
	char account_number[20];
	char bank_name[20];
	char branch_name[20];
	char account_holder_name[20];
	char address[20];
	char ifsc[20];
	char status;

};
struct account_fields bank;
FILE *fp;
int record_found = 0;
int choice;
void show_menu();
void create();
void read();
void display();
void print_record();
void search();
void update();
void update_data();
void delete();
void modify_date();
void main()
{
	while(1)
	{
		show_menu();
	}
}
void show_menu()
{
	printf("\n********* WELCOME TO THE BANK APPLICATION **********\n");
	printf("\nPlease choose: \n");
	printf("\n1. New account.\n2. Display All accounts.\n3. Update an account.\n4. Delete an account.\n5. Serach an account.\n6. exit.\n");
	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1: create();
		break;
		case 2: read();
		break;
		case 3: update();
		break;
		case 4: delete();
		break;
		case 5: search();
		break;
		case 6: exit(0);
		break;
		default: 
		printf("\nInvalid Choice! Please Try Again.\n");
		break;
	}
}
void create()
{
	int no_of_accounts;
	fp = fopen(BANK_DATA_FILE, "a");
	printf("\nHow many accounts do you want to create: ");
	scanf("%d", &no_of_accounts);
	fflush(stdin);
	for(int account = 1; account <= no_of_accounts; account++)
	{
		printf("\nEnter Account Number: ");
		gets(bank.account_number);
		printf("\nEnter Account Holder Name: ");
		gets(bank.account_holder_name);
		printf("\nEnter Bank Name: ");
		gets(bank.bank_name);
		printf("\nEnter Branch Name: ");
		gets(bank.branch_name);
		printf("\nEnter Address: ");
		gets(bank.address);
		printf("\nEnter IFSC code: ");
		gets(bank.ifsc);
		bank.status = 'A';
		fwrite(&bank, sizeof(bank), 1, fp);
		if(account == no_of_accounts)
		{
			printf("\nAccount Has Been Created succesfully\n");
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
	char search_acc_no[20];
	record_found = 0;
	fp = fopen(BANK_DATA_FILE, "r");
	if(read_mode == 0)
	{
		while(fread(&bank, sizeof(bank), 1, fp))
		{
			print_record();
		}
		fclose(fp);
	}
	else
	{
		fflush(stdin);
		printf("\nEnter The Account Number You Want To Search: ");
		gets(search_acc_no);
		while(fread(&bank, sizeof(bank), 1, fp))
		{
			if(strcmp(bank.account_number, search_acc_no) == 0)
			{
				print_record();
			}
		}
		fclose(fp);
	}
	if(record_found == 0)
	{
		printf("\nFile does not exist.\n");
	}
}
void print_record()
{
	if(bank.status == 'A')
	{
		record_found++;
		if(record_found == 1)
		{
			printf("\n%18s%12s%15s%15s%18s%15s\n", "Account Number", "Name", "Bank Name", "Branch Name", "Address", "IFSC Code");
		}
		printf("\n%18s%12s%15s%15s%18s%15s\n", bank.account_number, bank.account_holder_name, bank.bank_name, bank.branch_name, bank.address, bank.ifsc);
	}
}
void update()
{
	modify_date("update");
}
void delete()
{
	modify_date("delete");
}
void modify_date(char mode[])
{
	record_found = 0;
	char modify_acc[20];
	fp = fopen(BANK_DATA_FILE, "r+");
	fflush(stdin);
	printf("\nEnter The Account Number you want to %s: ", mode);
	gets(modify_acc);
	while(fread(&bank, sizeof(bank), 1, fp))
	{
		if(strcmp(bank.account_number, modify_acc) == 0)
		{
			record_found++;
			if(strcmp(mode, "update") == 0)
			{
				printf("\n1. Update Bank Name.");
				printf("\n2. Update Branch Name.");
				printf("\n3. Update Account holder Name.");
				printf("\n4. Update Address.");
				printf("\n5. Update IFSC code.\n");
				printf("\nEnter your choice: ");
				scanf("%d", &choice);
				fflush(stdin);
				switch(choice)
				{
					case 1: 
					printf("\nEnter Bank Name: ");
					gets(bank.bank_name);
					update_data(fp);
					break;
					case 2: 
					printf("\nEnter Branch Name: ");
					gets(bank.branch_name);
					update_data(fp);
					break;
					case 3:
					printf("\nEnter Name: ");
					gets(bank.account_holder_name);
					update_data(fp);
					break;
					case 4: 
					printf("\nEnter BAddress: ");
					gets(bank.address);
					update_data(fp);
					break;
					case 5:
					printf("\nEnter IFSC code: ");
					gets(bank.ifsc);
					update_data(fp);
					break;
					default:
					printf("\nInvalid choice!\n");
					break;
				}
				break;
			}	
			else
			{
				bank.status = 'D';
				fseek(fp, (long)(long)(-sizeof(bank)), SEEK_CUR);
				fwrite(&bank, sizeof(bank), 1, fp);
				printf("\nDeleted succsefully.\n");
				break;
			}
		}
	}
	if(record_found == 0)
	{
		printf("\nInvalid Account Number\n");
	}
	fclose(fp);
}
void update_data(FILE *fp)
{
	fseek(fp, (long)(long)(-sizeof(bank)), SEEK_CUR);
	fwrite(&bank, sizeof(bank), 1, fp);
	printf("\nUpdated succsefully.\n");
}*/



//Framework for CRUD operation (bank domain).

/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MENU_FILE "menu1.cfg"
#define FIELDS_FILE "fields1.cfg"
#define DATA_FILE "database2.dat"
void count_of_fields();
void field_list();
void create();
void display();
void update();
void search();
void delete();
char menu_line[60], field_name[40], field_value[40], search_value[40], update_id[40];
int choice, count_of_field_values = 0, count_of_field_names, record_found = 0;
FILE *fp, *fp_data;
char **list_of_fields;
char active[10] = "active";
char inactive[10] = "inactive";
void main()
{
	count_of_fields();
	field_list();
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
			case 4: delete();
			break;
			case 5: search();
			break;
			case 6: exit(0);
			break;
			default:
			printf("\nInvalid Choice! Please Try Again.\n");
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
	fclose(fp_count_of_fields);
}
void field_list()
{
	fp = fopen(FIELDS_FILE, "r");
	count_of_field_values = 0;
	list_of_fields = malloc(count_of_field_names * sizeof(char*));
	while(fgets(field_name, sizeof(field_name), fp))
	{
		list_of_fields[count_of_field_values] = malloc(count_of_field_names * sizeof(char*));
		strcpy(list_of_fields[count_of_field_values], field_name);
		list_of_fields[count_of_field_values][strlen(list_of_fields[count_of_field_values]) - 1] = '\0';
		count_of_field_values++;
	}
	fclose(fp);
}
void create()
{
	int no_of_records;
	record_found = 0;
	fp_data = fopen(DATA_FILE, "a+");
	printf("\nHow many records do you want to create?: ");
	scanf("%d", &no_of_records);
	fflush(stdin);
	for(int record = 1; record <= no_of_records; record++)
	{
		count_of_field_values = 0;
		printf("\nEnter record %d: ", record);
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
		printf("\nFile does not exist.\n");
	}
	fclose(fp_data);
}
void display()
{
	fp_data = fopen(DATA_FILE, "r+");
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
		printf("\nFile does not exist.\n");
	}
	fclose(fp_data);	
}
void search()
{
	fp_data = fopen(DATA_FILE, "r");
	record_found = 0;
	if(fp_data != NULL)
	{
		printf("\nEnter %s to seach: ", list_of_fields[0]);
		gets(search_value);
		//fseek(fp_data, 0, SEEK_SET);
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
						count_of_field_values++;
					}
				}
			}
		}
	}
	if(record_found == 0)
	{
		printf("Invalid %s", list_of_fields[0]);
	}
	fclose(fp_data);
}
void update()
{
	fp_data = fopen(DATA_FILE, "r+");
	record_found = 0;
	if(fp_data != NULL)
	{
		printf("\nEnter %s to update: ", list_of_fields[0]);
		gets(update_id);
		//fseek(fp_data, 0, SEEK_SET);
		while(fread(field_value, sizeof(field_value), 1, fp_data))
		{
			if(strcmp(active, field_value) == 0)
			{
				fread(field_value, sizeof(field_value), 1, fp_data);
				if(strcmp(update_id, field_value) == 0)
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
					printf("\nEnter %s to update: ", list_of_fields[choice]);
					gets(field_value);
					fseek(fp_data, (long)(long)(-sizeof(field_value)), SEEK_CUR);
					fseek(fp_data,(choice*sizeof(field_value)), SEEK_CUR);
					fwrite(field_value, sizeof(field_value), 1, fp_data);
					printf("\nUpdated successfully\n");
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
	fp_data = fopen(DATA_FILE, "r+");
	record_found = 0;
	if(fp_data != NULL)
	{
		printf("\nEnter %s to delete: ", list_of_fields[0]);
		gets(search_value);
		while(fread(field_value, sizeof(field_value), 1, fp_data))
		{
			if(strcmp(active, field_value) == 0)
			{
				fread(field_value, sizeof(field_value), 1, fp_data);
				if(strcmp(field_value, search_value) == 0)
				{
					record_found++;
					count_of_field_values = 0;
					fseek(fp_data, (long)(long)(-2*sizeof(field_value)), SEEK_CUR);
					fwrite(inactive, sizeof(field_value), 1, fp_data);
					printf("\nDeleted succesfully\n");
					break;
				}
			}
		}
	}
	if(record_found == 0)
	{
		printf("\nFile does not exist.\n");
	}
	fclose(fp_data);
}*/

//Write a program to Split a given string into words.

/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void split();
void main()
{
	char input_string[20][25];
	char delim[]= " ,!";
	printf("\nEnter a string: ");
	gets(input_string);
	split(input_string, delim);
}
void split(char input_string[], char delim[])
{
	char *token = strtok(input_string, delim);
	while(token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
}*/





























































/*//Framework for crud operations.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MENU_FILE "show_menu.cfg"
#define FIELDS_FILE "fields.cfg"
#define DATA_FILE "database.dat"
void create();
void read();
void update();
void search();
void delete();
void count_of_fields();
void field_list();
int count_of_field_names, count_of_field_values = 0, record_found;
FILE *fp, *fp_field, *fp_data;
char menu_line[60];
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
			printf("\n");
			printf("%s", menu_line);
		}
		scanf("%d", &choice);
		fflush(stdin);
		switch(choice)
		{
			case 1: create();
			break;
			case 2: read();
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
			printf("\nInvalid choice! please try again.\n\n");
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
	fclose(fp_count_of_fields);
}
void field_list()
{
	fp = fopen(FIELDS_FILE, "r");
	list_of_fields = malloc(count_of_field_names * sizeof(char*));
	int count_of_field_values = 0;
	while(fgets(field_name, sizeof(field_name), fp))
	{
		list_of_fields[count_of_field_values] = malloc(count_of_field_names * sizeof(char*));
		strcpy(list_of_fields[count_of_field_values], field_name);
		list_of_fields[count_of_field_values][strlen(list_of_fields[count_of_field_values]) - 1] = '\0';
		count_of_field_values++;
	}
	fclose(fp);
}
void create()
{
	fp_data = fopen(DATA_FILE, "a+");
	record_found = 0;
	int no_of_records;
	printf("\nHow many records do you want to create?: ");
	scanf("%d", &no_of_records);
	fflush(stdin);
	for(int record_counter = 0; record_counter < no_of_records; record_counter++)
	{
		count_of_field_values = 0;
		printf("\nEnter emp_member %d: \n", record_counter + 1);
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
		printf("\nFile does not exist.\n\n");
	}
	fclose(fp_data);
}
void read()
{
	fp_data = fopen(DATA_FILE, "r+");
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
		printf("\nFile does not exist.\n\n");
	}
	fclose(fp_data);
}
void search()
{
	fp_data = fopen(DATA_FILE, "r");
	record_found = 0;
	if (fp_data != NULL)
	{
		printf("\nEnter %s to search: ", list_of_fields[0]);
		gets(search_value);		
		while(fread(field_value, sizeof(field_value), 1, fp_data))
		{
			if(strcmp(active, field_value) == 0)
			{
				fread(field_value, sizeof(field_value), 1, fp_data);
				if(strcmp(field_value, search_value) == 0)
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
	fp_data = fopen(DATA_FILE, "r+");
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
				if(strcmp(field_value, search_value) == 0)
				{
					record_found++;
					count_of_field_values = 0;
					printf("\nPlease select any field to update: \n\n");
					while(count_of_field_values < count_of_field_names - 1)
					{	
						//fread(read_string, sizeof(read_string), 1, fp_data);
						printf("%d. %s.\n", ++count_of_field_values, list_of_fields[count_of_field_values + 1]);
						//count_of_field_values++;
					}
					printf("\nEnter your choice: ");
					scanf("%d", &choice);
					fflush(stdin);
					if(choice > 0 && choice < count_of_field_names)
					{
						printf("\nEnter %s to update: ", list_of_fields[choice]);
						gets(field_value);
						fseek(fp_data,(long)(long)(-sizeof(field_value)), SEEK_CUR);
						fseek(fp_data,(choice * sizeof(field_value)), SEEK_CUR);
						fwrite(field_value, (sizeof(field_value)), 1, fp_data);
						printf("\nUpdated sucessfully.\n");
						//fseek(fp_data, 0, SEEK_SET);
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
	fp_data = fopen(DATA_FILE, "r+");
	record_found = 0;
	if (fp_data != NULL)
	{
		int choice;
		printf("\nEnter %s to delete: ", list_of_fields[0]);
		gets(search_value);
		fseek(fp_data,0, SEEK_SET);
		while(fread(field_value, sizeof(field_value), 1, fp_data))
		{
			if(strcmp(active, field_value) == 0)
			{
				fread(field_value, sizeof(field_value), 1, fp_data);	
				if(strcmp(field_value, search_value) == 0)
				{
					record_found++;
					count_of_field_values = 0;
					fseek(fp_data,(long)(long)(-2 * sizeof(field_value)), SEEK_CUR);
					fwrite(inactive, sizeof(field_value), 1, fp_data);
					printf("\nRecord Deleted.\n");
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
}*/













/*File = open("databaseFile.dat", "r")
listOfFields = ['Name', 'Age']
listOfNames = []
listOfNames = File.readlines()
print(listOfNames)
for index in range(len(listOfNames)):
	if index % len(listOfFields) == 0:
		for counter in range(len(listOfFields)):
			print(listOfFields[counter] + ": " + listOfNames[index + counter], end = "")
		print()*/
/*
//Framework for crud operations.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MENU_FILE "show_menu.cfg"
#define FIELDS_FILE "fields.cfg"
#define DATA_FILE "database.dat"
//#define COUNT_OF_CHARACTERS 50
void create();
void read();
void update();
void search();
void delete();
void count_of_fields();
void field_list();
int count_of_field_names, count_of_field_values = 0, record_found;
FILE *fp, *fp_field, *fp_data;
char menu_line[50];
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
				case 2: read();
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
				printf("\nInvalid choice.\n\n");
				break;
			}
			rewind(fp);
		}
	}
	else
	{
		printf("\nFile not found.\n");
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
	fclose(fp_count_of_fields);
}
void field_list()
{
	fp = fopen(FIELDS_FILE, "r");
	list_of_fields = malloc(count_of_field_names * sizeof(char*));
	int count_of_field_values = 0;
	while(fgets(field_name, sizeof(field_name), fp))
	{
		list_of_fields[count_of_field_values] = malloc(count_of_field_names * sizeof(char*));
		strcpy(list_of_fields[count_of_field_values], field_name);
		list_of_fields[count_of_field_values][strlen(list_of_fields[count_of_field_values]) - 1] = '\0';
		count_of_field_values++;
	}
	fclose(fp);
}
void create()
{
	record_found = 0;
	int no_of_records;
	fp_data = fopen(DATA_FILE, "a+");
	printf("\nHow many records do you want to create?: ");
	scanf("%d", &no_of_records);
	fflush(stdin);
	for(int record_counter = 0; record_counter < no_of_records; record_counter++)
	{
		count_of_field_values = 0;
		printf("\nEnter emp_member %d: \n", record_counter + 1);
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
		printf("\nFile does not exist.\n\n");
	}
	fclose(fp_data);
}
void read()
{
	fp_data = fopen(DATA_FILE, "r+");
	fseek(fp_data, 0, SEEK_SET);
	record_found = 0;
	while(fread(field_value, sizeof(field_value), 1, fp_data) == 1)
	{
		if(strcmp(active, field_value) == 0)
		{	
			printf("\n");
			count_of_field_values = 0;
			while(count_of_field_values < count_of_field_names)
			{
				fread(field_value, sizeof(field_value), 1, fp_data);
				printf("\n%s is: %s\n", list_of_fields[count_of_field_values], field_value);
				if(count_of_field_values == count_of_field_names - 1)
				{
					break;
				}
				count_of_field_values++;
				record_found++;
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
	fp_data = fopen(DATA_FILE, "r");
	record_found = 0;
	if (fp_data != NULL)
	{
		printf("\nEnter %s to search: ", list_of_fields[0]);
		gets(search_value);		
		while(fread(field_value, sizeof(field_value), 1, fp_data))
		{
			if(strcmp(active, field_value) == 0)
			{
				fread(field_value, sizeof(field_value), 1, fp_data);
				if(strcmp(field_value, search_value) == 0)
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
		printf("\nfield not found.\n");
	}
	fclose(fp_data);
}
void update()
{
	fp_data = fopen(DATA_FILE, "r+");
	record_found = 0;
	int choice;
	printf("\nEnter %s to update: ", list_of_fields[0]);
	gets(search_value);
	fseek(fp_data, 0, SEEK_SET);
	while(fread(field_value, sizeof(field_value), 1, fp_data))
	{
		if(strcmp(active, field_value) == 0)
		{
			fread(field_value, sizeof(field_value), 1, fp_data);
			if(strcmp(field_value, search_value) == 0)
			{
				record_found++;
				count_of_field_values = 0;
				printf("\nPlease select any field to update: \n\n");
				while(count_of_field_values < count_of_field_names - 1)
				{	
					//fread(read_string, sizeof(read_string), 1, fp_data);
					printf("%d. %s.\n", ++count_of_field_values, list_of_fields[count_of_field_values + 1]);
					//count_of_field_values++;
				}
				printf("\nEnter your choice: ");
				scanf("%d", &choice);
				fflush(stdin);
				if(choice > 0 && choice < count_of_field_names)
				{
					printf("\nEnter %s to update: ", list_of_fields[choice]);
					gets(field_value);
					fseek(fp_data,(long)(long)(-sizeof(field_value)), SEEK_CUR);
					fseek(fp_data,(choice * sizeof(field_value)), SEEK_CUR);
					fwrite(field_value, (sizeof(field_value)), 1, fp_data);
					printf("\nupdated sucessfully.\n");
					fseek(fp_data, 0, SEEK_SET);
				}
				break;
			}
		}
	}
	if(record_found == 0)
	{
		printf("\nfield not found.\n");
	}
	fclose(fp_data);
}
void delete()
{
	fp_data = fopen(DATA_FILE, "r+");
	record_found = 0;
	int choice;
	printf("\nEnter %s to delete: ", list_of_fields[0]);
	gets(search_value);
	fseek(fp_data,0, SEEK_SET);
	while(fread(field_value, sizeof(field_value), 1, fp_data))
	{
		if(strcmp(active, field_value) == 0)
		{
			fread(field_value, sizeof(field_value), 1, fp_data);	
			if(strcmp(field_value, search_value) == 0)
			{
				record_found++;
				count_of_field_values = 0;
				fseek(fp_data,(long)(long)(-2 * sizeof(field_value)), SEEK_CUR);
				fwrite(inactive, sizeof(field_value), 1, fp_data);
				printf("\nRecord Deleted.\n");
				break;
			}
		}
	}
	if(record_found == 0)
	{
		printf("\nfield not found.\n");
	}
	fclose(fp_data);
}
*/

