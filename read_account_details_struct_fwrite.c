/*
// Read account details and save it into a file using structure and file.

#include<stdio.h>
struct bank_account_details
{
	char bank_name[20];
	char branch_name[20];
	long long account_number;
	char account_holder_name[25];
	char ifsc_code[15];
	long long phone_number;
};
void main()
{
	FILE *fp_bank_account;
	fp_bank_account = fopen("bank_details.txt", "wb");
	if(fp_bank_account == NULL)
	{
		printf("File does not exist");
	}
	struct bank_account_details account_1;
	{
		printf("Enter your account details: \n");
		printf("Enter bank name: ");
		gets(account_1.bank_name);
		printf("Enter branch name: ");
		gets(account_1.branch_name);
		printf("Enter account number: ");
	  	scanf("%lld", &account_1.account_number);
	  	fflush(stdin);
		printf("Enter account_holder_name: ");
		gets(account_1.account_holder_name);
		printf("Enter IFSC code: "); 
		gets(account_1.ifsc_code);
		printf("Enter phone number: ");
		scanf("%lld", &account_1.phone_number);
		fflush(stdin);
		fprintf(fp_bank_account, "Bank name: ");
		fwrite(account_1.bank_name, sizeof(account_1.bank_name), 1, fp_bank_account);
		fprintf(fp_bank_account, "%s\n", account_1.bank_name);
		fprintf(fp_bank_account, "Branch name: ");
		fwrite(account_1.branch_name, sizeof(account_1.branch_name), 1, fp_bank_account);
		fprintf(fp_bank_account, "%s\n", account_1.branch_name);
		fprintf(fp_bank_account, "Account number: ");
		fwrite(&account_1.account_number, sizeof(account_1.account_number), 1, fp_bank_account);
		fprintf(fp_bank_account, "%lld\n", account_1.account_number);
		fprintf(fp_bank_account, "Account holder name: ");	
		fwrite(account_1.account_holder_name, sizeof(account_1.account_holder_name), 1, fp_bank_account);
		fprintf(fp_bank_account, "%s\n", account_1.account_holder_name);
		fprintf(fp_bank_account, "IFSC code: ");
		fwrite(account_1.ifsc_code, sizeof(account_1.ifsc_code), 1, fp_bank_account);
		fprintf(fp_bank_account, "%s\n", account_1.ifsc_code);
		fprintf(fp_bank_account, "Phone number: ");
		fwrite(&account_1.phone_number, sizeof(account_1.phone_number), 1, fp_bank_account);
		fprintf(fp_bank_account, "%lld\n", account_1.phone_number);
	};
	fclose(fp_bank_account);
}
*/


// Read account details and save it into a file using structure and fwrite().

#include<stdio.h>
#include<stdlib.h>
struct bank_account_details 
{
	char bank_name[20];
	char branch_name[20];
	long long account_number;
	char account_holder_name[25];
	char ifsc_code[15];
	long long phone_number;
};
void main()
{
	FILE *fp_bank_account;
	fp_bank_account = fopen("bank_details.txt", "wb");
	if(fp_bank_account == NULL)
	{
		printf("File does not exist");
	}
	struct bank_account_details account_1;
		printf("Enter your account details: \n");
		printf("Enter bank name: ");
		gets(account_1.bank_name);
		printf("Enter branch name: ");
		gets(account_1.branch_name);
		printf("Enter account number: ");
	  	scanf("%lld", &account_1.account_number);
	  	fflush(stdin);
		printf("Enter account_holder_name: ");
		gets(account_1.account_holder_name);
		printf("Enter IFSC code: "); 
		gets(account_1.ifsc_code);
		printf("Enter phone number: ");
		scanf("%lld", &account_1.phone_number);
		fflush(stdin);
		/*printf("%u,%u,%u\n", &account_1[0], account_1, &account_1[0].bank_name);
		 printf("%d\n", sizeof(account_1));
		 printf("%d\n", sizeof(account_1[0]));
		 printf("%d\n", sizeof(account_1[0].bank_name));
		ptrAccount = malloc(sizeof(account_1[0]));
		printf("%d,%d", sizeof(struct bank_account_details), sizeof(account_1[0]));*/
	/*int counter;
	printf("%d,%d", sizeof(int),sizeof(counter));*/
		fwrite(&account_1, sizeof(account_1), 1, fp_bank_account);
		fclose(fp_bank_account);
}
		/*fprintf(fp_bank_account, "Bank name: ");
		fwrite(account_1.bank_name, sizeof(account_1.bank_name), 1, fp_bank_account);
		fprintf(fp_bank_account, "%s\n", account_1.bank_name);
		fprintf(fp_bank_account, "Branch name: ");
		fwrite(account_1.branch_name, sizeof(account_1.branch_name), 1, fp_bank_account);
		fprintf(fp_bank_account, "%s\n", account_1.branch_name);
		fprintf(fp_bank_account, "Account number: ");
		fwrite(&account_1.account_number, sizeof(account_1.account_number), 1, fp_bank_account);
		fprintf(fp_bank_account, "%lld\n", account_1.account_number);
		fprintf(fp_bank_account, "Account holder name: ");	
		fwrite(account_1.account_holder_name, sizeof(account_1.account_holder_name), 1, fp_bank_account);
		fprintf(fp_bank_account, "%s\n", account_1.account_holder_name);
		fprintf(fp_bank_account, "IFSC code: ");
		fwrite(account_1.ifsc_code, sizeof(account_1.ifsc_code), 1, fp_bank_account);
		fprintf(fp_bank_account, "%s\n", account_1.ifsc_code);
		fprintf(fp_bank_account, "Phone number: ");
		fwrite(&account_1.phone_number, sizeof(account_1.phone_number), 1, fp_bank_account);
		fprintf(fp_bank_account, "%lld\n", account_1.phone_number);*/
	
