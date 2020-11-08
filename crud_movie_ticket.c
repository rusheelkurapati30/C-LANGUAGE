// Movie Ticket Booking Application.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BOOKING_FILE "booking.dat"
struct movie
{
	char movie_code[10];
	char movie_name[20];
	char release_date[20];
	int ticket_price;
	char status;
};
struct movie ticket_booking;
char search_code[10];
char code[5];
int age, no_of_tickets, seat_number[5];
long long mobile_no;char confirm;
int booking_id = 1000;
int record_found = 0;
char delete_code[5];
void show_menu();
void display();
void modify_data();
void update_data();
void print_record();
void book();
void create();
void read();
void update();
void search(); 
void delete();
void display_bookings();
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
	printf("\n****** Movie Ticket Booking ******\n");
	printf("\nPlease choose: \n1. Add New Movie\n2. Display All Movies\n3. Update/Book Ticket\n4. Search Movie\n5. Delete Movie\n6. Exit\n");
	printf("\n*******************************************\n");
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
		printf("\nError! Wrong Number is Entered, Please Try Again\n");
	}
}
void create()
{
	FILE *fp;
	fp = fopen(BOOKING_FILE, "a");
	if(fp == NULL)
	{
		printf("File does not exist");
		exit(0);
	}
	int no_of_movies;
	printf("\nHow many movies do you want to insert? : ");
	scanf("%d", &no_of_movies);
	fflush(stdin);
	for(int movie = 0; movie < no_of_movies; movie++)
	{
		printf("\nEnter Movie %d: \n", movie+1);
		fflush(stdin);
		printf("\nEnter Movie Code: ");
		gets(ticket_booking.movie_code);
		printf("\nEnter Movie Name: ");
		gets(ticket_booking.movie_name);
		printf("\nEnter Release Date: ");
		gets(ticket_booking.release_date);
		printf("\nEnter Ticket Price: ");
		scanf("%d", &ticket_booking.ticket_price);
		ticket_booking.status = 'A';
		fwrite(&ticket_booking, sizeof(ticket_booking), 1, fp);
		if(movie == no_of_movies - 1)
		{
			printf("\nInserted Succesfully\n");
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
	fp = fopen(BOOKING_FILE, "r+");
	if(fp == NULL)
	{
		printf("\nFile does not exist\n\n");
	}
	if(read_mode == 0)
	{
		record_found = 0;
		while(fread(&ticket_booking, sizeof(ticket_booking), 1, fp))
		{
			print_record();
		}
		fclose(fp);
	}
	else
	{
		char search_code[10];
		fflush(stdin);
		printf("\nEnter the movie code you want to search: ");
		gets(search_code);
		while(fread(&ticket_booking, sizeof(ticket_booking), 1, fp))
		{
			record_found = 0;
			if(strcmp(ticket_booking.movie_code, search_code) == 0)
			{
				print_record();
				break;
			}
		}
		if(strcmp(ticket_booking.movie_code, search_code) != 0)
		{
			printf("\nInvalid Movie Code\n");
	    }
		fclose(fp);
	}
}
void print_record()
{
	if(ticket_booking.status == 'A')
	{
		record_found++;
		if(record_found == 1)
		{
			printf("\n%5s%20s%22s%17s\n\n", "Movie Code", "Movie Name", "Release Date", "Ticket Price");
		}
		printf("\n%5s%23s%24s%15d\n\n", ticket_booking.movie_code, ticket_booking.movie_name, ticket_booking.release_date, ticket_booking.ticket_price);
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
	fp = fopen(BOOKING_FILE, "r+");
	record_found = 0;
	int select;
	printf("\nEnter the movie code you want to update/book: ");
	scanf("%s", code);
	while(fread(&ticket_booking, sizeof(ticket_booking), 1, fp))
	{
		if(strcmp(ticket_booking.movie_code, code) == 0)
		{
			record_found++;
			if(strcmp(mode, "update") == 0)
			{
				printf("\n1. Update Movie Code");
				printf("\n2. Update Movie Name");
				printf("\n3. Update Release Date");
				printf("\n4. Update Ticket Price");
				printf("\n5. Book Movie Ticket");
				printf("\n\nEnter your choice: ");
				scanf("%d", &select);
			    fflush(stdin);
				switch(select)
				{
					case 1:
					printf("\nEnter Movie Code: ");
					gets(ticket_booking.movie_code);
					update_data(fp);
					break;
					case 2:
					printf("\nEnter Movie Name: ");
					gets(ticket_booking.movie_name);
					update_data(fp);
					break;
					case 3:
					printf("\nEnter Release Date: ");
					gets(ticket_booking.release_date);
					update_data(fp);
					break;
					case 4: 
					printf("\nEnter Ticket Price: ");
					scanf("%d", &ticket_booking.ticket_price);
					fflush(stdin);
					update_data(fp);
					break;
					case 5:
					book();
					fseek(fp, (long long)(-sizeof(struct movie)), SEEK_CUR);
					fwrite(&ticket_booking, sizeof(ticket_booking), 1, fp);
					//record_found = 0;
					//print_record();
					break;
					default:
					printf("\nInvalid Selection\n");
					break;
				}
				break;
			}
			else if(strcmp(mode, "delete") == 0)
			{
				ticket_booking.status = 'D';
				fseek(fp, (long long)(-sizeof(struct movie)), SEEK_CUR);
				fwrite(&ticket_booking, sizeof(ticket_booking), 1, fp);
				record_found++;
				printf("\nRecord Deleted\n");
				break;
			}
		}
	}
	if(record_found == 0)
	{
		printf("\nInvalid Code\n");
	}
	fclose(fp);
}
void update_data(FILE *fp)
{
	fseek(fp, (long long)(-sizeof(struct movie)), SEEK_CUR);
	fwrite(&ticket_booking, sizeof(ticket_booking), 1, fp);
	printf("\n Record Updated\n");
}
void book()
{
	FILE *fp;
	fp = fopen(BOOKING_FILE, "r+");
	if(fp == NULL)
	{
		printf("\nFile does not exist\n\n");
	}
	fflush(stdin);
	printf("\nEnter the movie code you want to book: ");
	gets(search_code);
	while(fread(&ticket_booking, sizeof(ticket_booking), 1, fp))
	{
		if(strcmp(ticket_booking.movie_code, search_code) == 0)
		{
			record_found = 0;
			print_record();
			printf("** Fill Details **\n");
			printf("\nEnter your Mobile Number: ");
			scanf("%lld", &mobile_no);
			printf("\nEnter your Age: ");
			scanf("%d", &age);
			printf("\nHow many tickets do you want?: ");
			scanf("%d", &no_of_tickets);
			fflush(stdin);
			for(int ticket = 0; ticket < no_of_tickets; ticket++)
			{
				fflush(stdin);
				printf("\nEnter %d seat number: ", ticket+1);
				scanf("%d", &seat_number[ticket]);
			}
			fflush(stdin);
		}
		display_bookings(fp);
	}
}
void display_bookings(FILE *fp)
{
	fwrite(&ticket_booking, sizeof(ticket_booking), 1, fp);
	printf("\n-----Movie Ticket Booking Details-----\n");
	printf("\n%12s%18s%10s%15s%18s%15s\n", "Booking ID", "Mobile Number", "Age", "Total Seats", "Cost Per Ticket", "Total Amount");
	printf("\n%10d%17lld%12d%12d%15d%15d\n\n", booking_id, mobile_no, age, no_of_tickets, ticket_booking.ticket_price, no_of_tickets*ticket_booking.ticket_price);
	booking_id++;					
}