// C program to print the meaning of the given word using dictionary API.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<MMsystem.h>
#include<conio.h>
#define DATA_FILE_NAME "word_meaning.dat"
void get_api_data();
void to_lower_case();
void get_meaning();
char given_word[20], meaning[10000];
int counter;
char url[1000];
void main()
{
	printf("\nPlease enter a word: ");
	fgets(given_word, sizeof(given_word), stdin);
	given_word[strlen(given_word) - 1] = '\0';
	to_lower_case();
}
void get_api_data()
{
	sprintf(url, "curl -s -H \"app_id: cd9f1a0d\" -H \"app_key: 1f766ec01c258b21809ed532ff88579f\" \"https://od-api.oxforddictionaries.com/api/v2/entries/en-us/%s\" > %s", given_word, DATA_FILE_NAME);
	system(url);
	get_meaning();
}
void to_lower_case()
{
	counter = 0;
	while(counter < strlen(given_word))
	{
		given_word[counter] = tolower(given_word[counter]);
		counter++;
	}
	get_api_data();
}
void get_meaning()
{
	FILE *fp;
	char *char_pointer;
	int counter = 0;
	char delimiter[3] = "\"";
	fp = fopen(DATA_FILE_NAME, "r");
	fread(meaning, sizeof(meaning), 1, fp);
	//printf("%d", strlen(meaning));
	if(strlen(meaning) < 100)
	{
		printf("\nNo meaning found\n");
	}
	else
	printf("\nThe meaning of %s is: \n", given_word);
	char_pointer = strtok(meaning, delimiter);
	//printf("\n1...%s\n", char_pointer);
	while(char_pointer != NULL)
	{
		if (strstr(char_pointer, "definitions"))
		{
			//printf("\n2...%s\n", char_pointer);
			char_pointer = strtok(NULL, delimiter);
			//printf("\n3...%s\n", char_pointer);
			char_pointer = strtok(NULL, delimiter);
			//printf("\n4...%s\n", char_pointer);
			printf("\n%2d. %s\n", ++counter, char_pointer);
		}
		//char_pointer = strtok(NULL, delimiter);
		if(strstr(char_pointer, "audioFile"))
		{
			char_pointer = strtok(NULL, delimiter);
			char_pointer = strtok(NULL, delimiter);
			//printf("%s", char_pointer);
			sprintf(url,"curl -s %s> word.mp3", char_pointer);
			system(url);
			system("word.mp3 &");
			//PlaySound("word.mp3",0,SND_FILENAME|SND_SYNC);
			//system("vlc word.mp3");
			//PlaySound(TEXT("word.mp3"), NULL, SND_ASYNC);
		}
		char_pointer = strtok(NULL, delimiter);
	}
	fclose(fp);
}


























		/*counter++;
		char_pointer = strtok(NULL, delimiter);
		//printf("\n%s\n", char_pointer);
		if(counter == 11)
		{
			strcpy(meaning, char_pointer);
			//printf("\nMeaning is: %s\n", meaning);
			char_pointer = strtok(meaning, "\"");
			counter = 0;
			while(char_pointer != NULL)
			{
				counter++;
				//printf("\n%s\n", char_pointer);
				if(counter == 2)
				{
					strcpy(meaning, char_pointer);
					//printf("\n%s\n", meaning);
					break;
				}
				char_pointer = strtok(NULL, "\"");
			}
			break;
		}*/