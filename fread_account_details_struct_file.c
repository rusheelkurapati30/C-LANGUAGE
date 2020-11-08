
// Read all account details from the file and print them using fread().

/*#include<stdio.h>
struct bank_account_details
{
	char bank_name[20];
	char branch_name[20];
	unsigned long long account_number;
	char account_holder_name[25];
	char ifsc_code[15];
	unsigned long long phone_number;
};
void main()
{
	struct bank_account_details account_1;
	FILE *fp_bank_account;
	fp_bank_account = fopen("bank_details.txt", "rb");
	fread(account_1.bank_name, sizeof(account_1.bank_name), 1, fp_bank_account);
	printf("Bank name: %s\n", account_1.bank_name);
	fread(account_1.branch_name, sizeof(account_1.branch_name), 1, fp_bank_account);
	printf("Branch name: %s\n", account_1.branch_name);
	fread(&account_1.account_number, sizeof(account_1.account_number), 1, fp_bank_account);
	printf("Account number: %llu\n", account_1.account_number);	
	fread(account_1.account_holder_name, sizeof(account_1.account_holder_name), 1, fp_bank_account);
	printf("Account holder name: %s\n", account_1.account_holder_name);
	fread(&account_1.ifsc_code, sizeof(account_1.ifsc_code), 1, fp_bank_account);
	printf("IFSC code: %s\n", account_1.ifsc_code);
	fread(&account_1.phone_number, sizeof(account_1.phone_number), 1, fp_bank_account);
	printf("Phone number: %llu\n", account_1.phone_number);
	fclose(fp_bank_account);
}	*/

/*#include<stdio.h>
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
	struct bank_account_details account_1;
	FILE *fp_bank_account;
	fp_bank_account = fopen("bank_details.txt", "r");
	if(fp_bank_account == NULL)
	{
		printf("File doesn't exist.");
	}
	while(fread(&account_1, sizeof(account_1), 1, fp_bank_account) > 0)
	{
		printf("Bank name: %s\n", account_1.bank_name);
		printf("Branch name: %s\n", account_1.branch_name);
		printf("Account number: %lld\n", account_1.account_number);
		printf("Account holder name: %s\n", account_1.account_holder_name);
		printf("IFSC code: %s\n", account_1.ifsc_code);
		printf("Phone number: %lld\n", account_1.phone_number);
	}
	fclose(fp_bank_account);
}*/


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
	struct bank_account_details account_1[2];
	FILE *fp_bank_account;
	fp_bank_account = fopen("bank_details.txt", "r");
	if(fp_bank_account == NULL)
	{
		printf("File doesn't exist.");
	}
	while(fread(&account_1, sizeof(account_1[0]), 5, fp_bank_account) > 0)
	{
		printf("Bank name: %s\n", account_1[0].bank_name);
		printf("Branch name: %s\n", account_1[0].branch_name);
		printf("Account number: %lld\n", account_1[0].account_number);
		printf("Account holder name: %s\n", account_1[0].account_holder_name);
		printf("IFSC code: %s\n", account_1[0].ifsc_code);
		printf("Phone number: %lld\n", account_1[0].phone_number);
	}
	fclose(fp_bank_account);
}
	


























	/*printf("Bank name: ");
	fread(account_1.bank_name, sizeof(account_1.bank_name), 1, fp_bank_account);
	printf("%s\n", account_1.bank_name);
	printf("Branch name: ");
	fread(account_1.branch_name, sizeof(account_1.branch_name), 1, fp_bank_account);
	printf("%s\n", account_1.branch_name);
	printf("Account number: ");
	fread(&account_1.account_number, sizeof(account_1.account_number), 1, fp_bank_account);
	printf("%lld\n", account_1.account_number);
	printf("Account holder name: ");
	fread(account_1.account_holder_name, sizeof(account_1.account_holder_name), 1, fp_bank_account);
	printf("%s\n", account_1.account_holder_name);
	printf("IFSC code: ");
	fread(&account_1.ifsc_code, sizeof(account_1.ifsc_code), 1, fp_bank_account);
	printf("%s\n", account_1.ifsc_code);
	printf("Phone number: ");
	fread(&account_1.phone_number, sizeof(account_1.phone_number), 1, fp_bank_account);
	printf("%lld\n", account_1.phone_number);
	fclose(fp_bank_account);*/
	