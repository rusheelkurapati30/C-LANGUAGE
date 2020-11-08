// HOSPITAL MANAGEMENT SYSTEM APPLICATION.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HOSPITAL_MANAGEMENT_FILE "patients_info.dat"
struct hospital
{
	int patient_id;
	char name[20];
	char disease[20];
	char date[15];
	char discharge_date[15];
	int age;
	int room_num;
	long long mobile_no;
	char status;
	float bill_amount;
};
struct hospital patient_details;
int record_found = 0;
void show_menu();
void display();
void print_record();
void modify_data();
void update_data();
void bill_update();
void create();
void read();
void search();
void update();
void delete();
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
	printf("\n************ HOSPITAL MANAGEMENT SYSTEM ************\n");
	printf("\nPlease choose: \n\n1. New Patient \n2. View All Patients\n3. Update Information\n4. Delete Information\n5. Search\n6. exit\n");
	printf("-------------------------------------------------------\n");
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
		printf("\nError! Wrong Number is Entered, Please Try Again\n");
	}
}
void create()
{
	FILE *fp;
	fp = fopen(HOSPITAL_MANAGEMENT_FILE, "a");
	if(fp == NULL)
	{
		printf("File does not exist");
		exit(0);
	}
	int no_of_patients;
	printf("\nHow many patient details do you want to add?: ");
	scanf("%d", &no_of_patients);
	fflush(stdin);
	for(int patient = 0; patient < no_of_patients; patient++)	
	{
		printf("\nEnter patient %d details: \n", patient + 1);
		printf("\nEnter patient id: ");
		scanf("%d", &patient_details.patient_id);
		fflush(stdin);
		printf("\nEnter admit date (dd/mm/yy): ");
		gets(patient_details.date);
		printf("\nEnter patient name: ");
		gets(patient_details.name);
		printf("\nEnter disease/problem: ");
		gets(patient_details.disease);
		printf("\nEnter age: ");
		scanf("%d", &patient_details.age);
		printf("\nEnter room number: ");
		scanf("%d", &patient_details.room_num);
		printf("\nEnter mobile number: ");
		scanf("%lld", &patient_details.mobile_no);
		patient_details.status = 'A';
		patient_details.bill_amount = 0;
		fwrite(&patient_details, sizeof(patient_details), 1, fp);
		if(patient == no_of_patients - 1)
		{
			printf("\nPatient Details Added Successfully.\n\n");
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
	fp = fopen(HOSPITAL_MANAGEMENT_FILE, "r+");
	if(fp == NULL)
	{
		printf("\nFile does not exist\n\n");
	}
	if(read_mode == 0)
	{
		record_found = 0;
		while(fread(&patient_details, sizeof(patient_details), 1, fp))
		{
			print_record();
		}
		fclose(fp);
	}
	else
	{
		int search_id;  
		printf("\nEnter the patient ID you want to search: ");
		scanf("%d", &search_id);
		if(search_id == 0)
		{
			printf("Patient ID %d is not available in the file.\n", search_id);
		}
		while(fread(&patient_details, sizeof(patient_details), 1, fp))
		{
			if(patient_details.patient_id == search_id)
			{	
				record_found = 0;
				print_record();
				break;
			}
			if(record_found == 0)
			{
				printf("\nInvalid ID\n");
				break;
		    }
		}
		fclose(fp);
	}
}
void print_record()
{
	if(patient_details.status == 'A')
	{
		record_found++;
		if(record_found == 1)
		{
			printf("\n%5s%15s%20s%20s%10s%15s%15s%15s%20s\n", "ID", "Admit Date", "Name", "Disease/Problem", "Age", "Room Number", "Mobile Number", "Bill Amount", "Discharge Date");	
		}
		printf("\n%5d%15s%20s%20s%10d%13d%15lld%15.2f%20s\n\n", patient_details.patient_id, patient_details.date, patient_details.name, patient_details.disease, patient_details.age, patient_details.room_num, patient_details.mobile_no, patient_details.bill_amount, patient_details.discharge_date);
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
	FILE *fp;
	fp = fopen(HOSPITAL_MANAGEMENT_FILE, "r+");
	int id, select;
	record_found = 0;
	printf("\nEnter the patient ID you want to %s: ", mode);
	scanf("%d", &id);
	while(fread(&patient_details, sizeof(patient_details), 1, fp))
	{
		if(patient_details.patient_id == id)
		{
			record_found++;
			if(strcmp(mode, "update") == 0)
			{
				printf("\n1. Update Name");
				printf("\n2. Update Disease/Problem Name");
				printf("\n3. Update Age");
				printf("\n4. Update Room Number");
				printf("\n5. Update Mobile Number");
				printf("\n6. Update Bill Amount");
				printf("\n7. Update Discharge Date");
				printf("\n\nEnter your choice: ");
				scanf("%d", &select);
			    fflush(stdin);
				switch (select)
				{
					case 1:
					printf("\nEnter patient name: ");
					gets(patient_details.name);
					update_data(fp);
					break;
					case 2:
					printf("\nEnter disease/problem name: ");
					gets(patient_details.disease);
					update_data(fp);
					break;
					case 3:
					printf("\nEnter age: ");
					scanf("%d", &patient_details.age);
					fflush(stdin);
					update_data(fp);
					break;
					case 4: 
					printf("\nEnter room number: ");
					scanf("%d", &patient_details.room_num);
					fflush(stdin);
					update_data(fp);
					break;
					case 5: 
					printf("\nEnter mobile number: ");
					scanf("%d", &patient_details.mobile_no);
					fflush(stdin);
					update_data(fp);
					break;
					case 6: 
					printf("\nUpdate Bill Amount: \n");
					bill_update();
					update_data(fp);
					record_found = 0;
					print_record();
					break;
					case 7:
					fflush(stdin);
					printf("\nUpdate Discharge Date: ");
					gets(patient_details.discharge_date);
					default:
					printf("\nInvalid Selection\n");
					break;
				}
				break;
			}
			else if(strcmp(mode, "delete") == 0)
			{
				patient_details.status = 'D';
				fseek(fp, (long long)(-sizeof(struct hospital)), SEEK_CUR);
				fwrite(&patient_details, sizeof(patient_details), 1, fp);
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
	fclose(fp);
}
void update_data(FILE *fp)
{
	fseek(fp, (long long)(-sizeof(struct hospital)), SEEK_CUR);
	fwrite(&patient_details, sizeof(patient_details), 1, fp);
	printf("\n Record Updated\n");
}
void bill_update()
{
	float room_charges, medicine_charges, doctor_fee, total_due;
	printf("\nCharges: \n");
	printf("\nRoom Charges: ");
	scanf("%f", &room_charges);
	printf("\nDoctor Fee: ");
	scanf("%f", &doctor_fee);
	printf("\nMedicine Charges: ");
	scanf("%f", &medicine_charges);
	fflush(stdin);
	printf("\nDischarge date (dd/mm/yy): ");
	gets(patient_details.discharge_date);
	patient_details.bill_amount = room_charges + doctor_fee + medicine_charges;
	printf("\nTotal Due = %0.2f\n", patient_details.bill_amount);	
}





































