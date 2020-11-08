
// Read account details and print them using structures.

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
void main(){
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
		printf("------Your bank account details are: --------\n");
		printf("Name of the bank: %s\n", account_1.bank_name);
		printf("Name of the branch: %s\n", account_1.branch_name);
		printf("Account number: %llu\n", account_1.account_number);
		printf("Account holder name: %s\n", account_1.account_holder_name);
		printf("IFSC code: %s\n", account_1.ifsc_code);
		printf("Phone number: %llu", account_1.phone_number);
	};
}
