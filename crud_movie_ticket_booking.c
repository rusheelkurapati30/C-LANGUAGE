// Movie Ticket Booking Application.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BOOKING_FILE "ticket_booking.dat"
struct movie
{
	char movie_code[10];
	char movie_name[20];
	char release_date[20];
	int ticket_price;
	char status;
	char booking_status;
	int  select_seat;
	//int booking_id;
};
struct movie ticket_booking;
int booking_id = 1000;
int selected_seat;
int record_found = 0;
char code[5];
char delete_code[5];
long long mobile_num;
int age;
void show_menu();
void display();
void modify_data();
void update_data();
void print_record();
void display_bookings();
void create();
void read();
void update();
void search(); 
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
	printf("\n******* Movie Ticket Booking *******\n");
	printf("\nPlease choose: \n1. Add New Movie\n2. Display All Movies\n3. Update/Book Ticket/Cancel Ticket\n4. Search Movie\n5. Delete Movie\n6. Exit\n");
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
	printf("\nHow many movies do you want to insert?: ");
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
	read();
	printf("\nEnter the Movie code you want to update/book ticket/cancel ticket: ");//you want to %s:", mode);
	scanf("%s", code);
	fflush(stdin);
	modify_data("update");
}
void delete()
{
	read();
	printf("\nEnter the movie code you want to delete: ");
	scanf("%s", delete_code);
	fflush(stdin);
	modify_data("delete");
}
void modify_data(char mode[])
{
	FILE *fp;
	fp = fopen(BOOKING_FILE, "r+");
	record_found = 0;
	while(fread(&ticket_booking, sizeof(ticket_booking), 1, fp))
	{
		int seat;
	    int array[seat];
		if(strcmp(mode, "update") == 0)
		{
			if(strcmp(ticket_booking.movie_code, code) == 0)
			{
				record_found++;
				int select1, select2;
				printf("\n1. To Update Movie Details.");
				printf("\n2. To Book A Movie Ticket.\n");
				printf("\nEnter your choice: ");
				scanf("%d", &select1);
				if(select1 >2)
				{
					printf("\nInvalid Selection\n");
					break;
				}
				if(select1 == 1)
				{
					printf("\n1. Update Movie Code");
					printf("\n2. Update Movie Name");
					printf("\n3. Update Release Date");
					printf("\n4. Update Ticket Price");
					printf("\n\nEnter your choice: ");
					scanf("%d", &select2);
				    fflush(stdin);
					switch(select2)
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
						default:
						printf("\nInvalid Selection\n");
						break;
					}
					break;
				}
				if(select1 == 2)
				{
					printf("\n");
					for(seat = 1; seat <= 100; seat++)
					{
						if(array[seat]==0)
						{
				        	printf("%d\t",seat);
				        }
				      	else
				      	{
				        	printf("*\t",seat);
				        } 
				      	if(seat%10==0)
				      	{
				        	printf("\n\n");
				        }
					}
					printf("\nWhich seat number you want?: ");
				    scanf("%d", &ticket_booking.select_seat);
				    if(ticket_booking.select_seat > 100 || ticket_booking.select_seat < 1)
				    {
				        printf("\nseat number is unavailable in this theater\n");
				        printf("\nPlease re-enter seat number: ");
				        scanf("%d", &ticket_booking.select_seat);
				    }
				    if(array[ticket_booking.select_seat] == 1)
				    {
				        printf("\nSorry, this ticket is already booked.\n");
				        while(array[ticket_booking.select_seat] == 1)
				        {
				     	  	printf("\nPlease re-enter seat number: ");
				       		scanf("%d",&ticket_booking.select_seat);
				        	printf("\nSorry, this ticket is already booked.\n");
				    	}
				    }
				    if(array[ticket_booking.select_seat] != 1)
				    {
				    	record_found == 0;
				    	array[ticket_booking.select_seat]=1;
				  		array[seat] = array[ticket_booking.select_seat];
				  		printf("\nEnter Mobile Number: ");
				  		scanf("%lld", &mobile_num);
				  		printf("\nEnter Age: ");
				  		scanf("%d", &age);
				  		printf("\nTicket Booked\n");
				  		ticket_booking.booking_status = 'B';
				  		fwrite(&ticket_booking, sizeof(ticket_booking), 1, fp);
						display_bookings(fp);
				    }
				}
				
			}
		}		
		else if(strcmp(mode, "delete") == 0)
		{
			if(strcmp(ticket_booking.movie_code, delete_code) == 0)
			{
				record_found++;
				ticket_booking.status = 'D';
				update_data(fp);
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
void display_bookings()	
{	
	printf("\n-----Movie Ticket Booking Details-----\n");
	//record_found++;
	//if(record_found == 1)
	//{
	printf("\n%10s%15s%8s%15s%15s\n\n", "Booking ID", "Mobile Number", "Age", "Seat Number", "Total Amount");
	//}
	printf("\n%8d%14lld%10d%10d%14d\n\n", booking_id, mobile_num, age, ticket_booking.select_seat, ticket_booking.ticket_price);
	booking_id++;
}
void update_data(FILE *fp)
{
	fseek(fp, (long long)(-sizeof(struct movie)), SEEK_CUR);
	fwrite(&ticket_booking, sizeof(ticket_booking), 1, fp);
	printf("\n Record Updated\n");
}




















/*void book_ticket()
{
	FILE *fp;
	fp = fopen(BOOKING_FILE, "r+");
	if(fp == NULL)
	{
		printf("\nFile does not exist\n\n");
	}
	char search_code[10];
	int age, booking_id, no_of_tickets, seat_number[5];
	long long mobile_no;char confirm;
	fflush(stdin);
		printf("\nEnter the movie code you want to book: ");
		gets(search_code);
		while(fread(&ticket_booking, sizeof(ticket_booking), 1, fp))
		{
			if(strcmp(ticket_booking.movie_code, search_code) == 0)
			{
				record_found = 0;
				print_record();
				printf("*** Fill Details ***\n");
				printf("\nEnter Booking ID: ");
				scanf("%d", &booking_id);
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
				printf("\n1. To confirm press(y)\n2. To cancel press(n)\n");
				scanf("%c", &confirm);
				if(confirm == 'n')
				{
					show_menu();
					break;
				}
			}
				
				display_bookings();

		}
}
void display_bookings(FILE *fp;)
{
				fwrite(&ticket_booking, sizeof(ticket_booking), 1, fp);
				printf("\n-----Movie Ticket Booking Details-----\n");
				printf("\nBooking ID: %d\n", booking_id);
				printf("\nMobile Number: %d\n", mobile_no);
				printf("\nAge: %d\n", age);
				printf("\nTotal Seats: %d\n", no_of_tickets);
				printf("\nSeat numbers: %d", seat_number[]);
				printf("\nCost Per Ticket: %d\n",ticket_booking.ticket_price);
				printf("\nTotal Amount: %d\n", no_of_tickets*ticket_booking.ticket_price);
					
}*/



















































// Movie Ticket Booking Application.

/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NO_OF_SEATS 100
#define BOOKING_FILE "ticket_booking.dat"
struct movie
{
	char movie_code[10];
	char movie_name[20];
	char release_date[20];
	int ticket_price;
	char status;
	int balance;
};
struct movie ticket_booking;
int record_found = 0;
char code[5];
char delete_code[5];
void show_menu();
void display();
void modify_data();
void update_data();
void print_record();
void display_bookings();
void create();
void read();
void update();
void search(); 
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
	printf("\n******* Movie Ticket Booking *******\n");
	printf("\nPlease choose: \n1. Add New Movie\n2. Display All Movies\n3. Update/Book Ticket/Cancel Ticket\n4. Search Movie\n5. Delete Movie\n6. Exit\n");
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
	read();
	printf("\nEnter the Movie code you want to update/book ticket/cancel ticket: ");//you want to %s:", mode);
	scanf("%s", code);
	fflush(stdin);
	modify_data("update");
}
void delete()
{
	read();
	printf("\nEnter the movie code you want to delete: ");
	scanf("%s", delete_code);
	fflush(stdin);
	modify_data("delete");
}
void modify_data(char mode[])
{
	FILE *fp;
	fp = fopen(BOOKING_FILE, "r+");
	record_found = 0;
	while(fread(&ticket_booking, sizeof(ticket_booking), 1, fp))
	{
		if(strcmp(mode, "update") == 0)
		{
			if(strcmp(ticket_booking.movie_code, code) == 0)
			{
				record_found++;
				int select1, select2;
				printf("\n1. To Update Movie Details.");
				printf("\n2. To Book A Movie Ticket.");
				printf("\n3. To Cancel A Movie Ticket.\n");
				printf("\nEnter your choice: ");
				scanf("%d", &select1);
				if(select1 >3)
				{
					printf("\nInvalid Selection\n");
					break;
				}
				if(select1 == 1)
				{
					printf("\n1. Update Movie Code");
					printf("\n2. Update Movie Name");
					printf("\n3. Update Release Date");
					printf("\n4. Update Ticket Price");
					printf("\n\nEnter your choice: ");
					scanf("%d", &select2);
				    fflush(stdin);
					switch(select2)
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
						default:
						printf("\nInvalid Selection\n");
						break;
					}
					break;
				}
			}
		}
		else if(strcmp(mode, "delete") == 0)
		{
			if(strcmp(ticket_booking.movie_code, delete_code) == 0)
			{
				record_found++;
				ticket_booking.status = 'D';
				update_data(fp);
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

					/*if(select1 == 2)
					{
						int  select_seat, i;
						while(fread(&ticket_booking, sizeof(ticket_booking), 1, fp))
						{
							int array[i];
						 for (i=1;i<=100;i++)
				    {
				      if (array[i]==0)
				        printf("%d\t",i);
				      else
				        printf("*\t",i); 
				      if(i%10==0)
				        printf("\n\n");
				    }
				  
				    printf("Which seat number you want? ");
				    scanf("%d",&select_seat);
				    if (select_seat>100||select_seat<1)
				      {
				        printf("seat1 number is unavailable in this theater\n");
				        printf("Please re-enter seat number: ");
				        scanf("%d",&select_seat);
				      }
				    if (array[select_seat]==1)
				      {
				        printf("Sorry, this ticket is already booked.\n");
				        while(array[select_seat] == 1)
				        {
				        printf("Please re-enter seat number: ");
				        scanf("%d",&select_seat);
				        printf("Sorry, this ticket is already booked.\n");
				    }
				      }
				      if(array[select_seat] != 1)
				      {
				      array[select_seat]=1;
				  		array[i]==array[select_seat];
				  		printf("tickets booked\n");
				}}}
*/
/*void update_data(FILE *fp)
{
	fseek(fp, (long long)(-sizeof(struct movie)), SEEK_CUR);
	fwrite(&ticket_booking, sizeof(ticket_booking), 1, fp);
	printf("\n Record Updated\n");
}
*/





/*if(select1 == 3)
				{
					int cancel;
					printf("\nEnter Seat Number to cancel the ticket: ");
					scanf("%d", &cancel);
					fflush(stdin);
					printf("cancel: %d", cancel);
					printf("selected seat: %d", ticket_booking.select_seat);
						if(cancel == ticket_booking.select_seat)
						{
							ticket_booking.booking_status = 'C';
							printf("your seat %d is cancelled",ticket_booking.select_seat);
							array[ticket_booking.select_seat] = 0;
							printf("\nTicket Cancelled Succesfully\n");
							update_data(fp);
						}
					}*/

				
			