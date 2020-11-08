// Program on weather_report to check the temperature.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void check_temperature();
char temperature[5];
void main()
{
	char location[20], command[1000];
	printf("\nEnter Location Name: ");
	gets(location);
	sprintf(command, "CURL -s \"http://api.openweathermap.org/data/2.5/weather?q=%s&appid=4167ebf679542684b2a0cb8a58701c27&units=metric\"> weather.dat", location);
	system(command);
	//printf("%s", command);
	check_temperature();
	if(atoi(temperature) != '\0')
	{
		printf("\nTemperature in %s is: %sC.\n", location, temperature);
	}
	else
	{
		printf("\nInvalid location.\n");
	}
}
void check_temperature()
{
	char *char_pointer;
	char weather_report[1000], delimiter[2] = ",";
	int counter = 0;
	FILE *fp;
	fp = fopen("weather.dat", "r");		
	fgets(weather_report, sizeof(weather_report), fp);
	char_pointer = strtok(weather_report, delimiter);
	printf("\n%s\n", char_pointer);
	while(char_pointer != NULL)
	{
		counter++;
		char_pointer = strtok(NULL, delimiter);
		printf("\n%s\n", char_pointer);
		if(counter == 7)
		{
			strcpy(temperature, char_pointer);
			printf("\nTemp is: %s\n", temperature);
			char_pointer = strtok(temperature, ":");
			counter = 0;
			while(char_pointer != NULL)
			{
				counter++;
				printf("\n%s\n", char_pointer);
				if(counter == 3)
				{
					strcpy(temperature, char_pointer);
					break;
				}
				char_pointer = strtok(NULL, ":");
			}
			break;
		}
	}
	fclose(fp);
}






















/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	FILE *fp;
	int counter = 0;
	char weather_report[1000], temperature[25], delimiter[2] = ",";
	char *char_pointer;
	char location[20], command[1000];
	printf("\nEnter Location Name: ");
	gets(location);
	sprintf(command, "CURL \"http://api.openweathermap.org/data/2.5/weather?q=%s&appid=4167ebf679542684b2a0cb8a58701c27&units=metric\"> weather.dat", location);
	system(command);
	//printf("%s", command);
	fp = fopen("weather.dat", "r");
	fgets(weather_report, sizeof(weather_report), fp);
	char_pointer = strtok(weather_report, delimiter);
	printf("\n%s\n", char_pointer);
	while(char_pointer != NULL)
	{
		counter++;
		char_pointer = strtok(NULL, delimiter);
		printf("\n%s\n", char_pointer);
		if(counter == 7)
		{
			strcpy(temperature, char_pointer);
			printf("\nTemp is: %s\n", temperature);
			char_pointer = strtok(temperature, ":");
			counter = 0;
			while(char_pointer != NULL)
			{
				counter++;
				printf("\n%s\n", char_pointer);
				if(counter == 3)
				{
					strcpy(temperature, char_pointer);
					break;
				}
				char_pointer = strtok(NULL, ":");
			}
			break;
		}
	}
	if(atoi(temperature) != '\0')
	{
		printf("\nTemperature in %s is: %sC.\n", location, temperature);
	}
	else
	{
		printf("\nInvalid location.\n");
	}
	fclose(fp);
}*/

