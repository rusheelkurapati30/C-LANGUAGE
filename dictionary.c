// Program to convert english word to hindi meaning.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define WORD_TRANSLATION "source_code.dat"
void get_meaning_page();
void extract_meaning();
void to_lower_case();
char meaning_in_hindi[100], converted_word[20];
char search_word[50], command[100000];
void main()
{
	printf("\nEnter the word to convert from english to hindi: ");
	//gets(search_word);
	fgets(search_word, sizeof(search_word), stdin);
	search_word[strlen(search_word) - 1] = '\0';
	to_lower_case();
	extract_meaning();
	if(meaning_in_hindi != NULL)
	{
		printf("\nMeaning of %s in hindi is: %s.\n", converted_word, meaning_in_hindi);
	}
	else
	{
		printf("\nInvalid Word.\n");
	}
}
void get_meaning_page()
{
	sprintf(command, "curl -s \"https://hindi.oneindia.com/dictionary/%s-meaning-in-hindi/\" > %s", converted_word, WORD_TRANSLATION);
	system(command);
	extract_meaning();
}
void to_lower_case()
{
	int counter = 0;
	while(counter < strlen(search_word))
	{
		search_word[counter] = tolower(search_word[counter]);
		counter++;
	}
	strcpy(converted_word, search_word);
	get_meaning_page();
}
void extract_meaning()
{
	char *char_pointer;
	char translation[100000], delimiter[3] = "<";
	int counter = 0;
	FILE *fp;
	fp = fopen(WORD_TRANSLATION , "r");
	while(fread(&translation, sizeof(translation),1, fp))
	{
		//printf("%s", translation);
		char_pointer = strtok(translation, delimiter);
		//printf("\n1. char_pointer: %s\n", char_pointer);
		while(char_pointer != NULL)
		{
			counter++;
			char_pointer = strtok(NULL, delimiter);
			//printf("counter = %d", counter);
			//printf("\n2. char_pointer: %s\n", char_pointer);
			//if(counter == 1074)                                                                                                                                                                 
			if(counter == 959)                                                                                                                                                                 
			{
				strcpy(meaning_in_hindi, char_pointer);
				//printf("\n3. meaning in hindi: %s", meaning_in_hindi);
				char_pointer = strtok(meaning_in_hindi, ">");
				counter = 0;
				while(char_pointer != NULL)
				{
					counter++;
					//printf("\n3. char_pointer: %s\n", char_pointer);
					if(counter == 2)
					{
						strcpy(meaning_in_hindi, char_pointer);
						//printf("%s", meaning_in_hindi);
						break;
					}
					char_pointer = strtok(NULL, ">");
				}
				//break;
			}
			//break;
		}
	}
	fclose(fp);
}














/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define WORD_TRANSLATION "source_code.dat"
void get_meaning_page();
void extract_meaning();
void to_lower_case();
char meaning_in_hindi[100];
char search_word[50], command[100000];
void main()
{
	printf("\nEnter the word to convert from english to hindi: ");
	//gets(search_word);
	fgets(search_word, sizeof(search_word), stdin);
	search_word[strlen(search_word) - 1] = '\0';
	to_lower_case();
	if(meaning_in_hindi != NULL)
	{
		printf("\nMeaning of %s in hindi is: %s.\n", search_word, meaning_in_hindi);
	}
	else
	{
		printf("\nInvalid Word.\n");
	}
}
void get_meaning_page()
{
	//printf("\n%s", search_word);
	sprintf(command, "curl -s \"https://hindi.oneindia.com/dictionary/%s-meaning-in-hindi/\" > %s", search_word, WORD_TRANSLATION);
	//printf("\n%s\n", command);
	//system("curl https://hindi.oneindia.com/dictionary/achieve-meaning-in-hindi/ > aa.dat");
	system(command);
	extract_meaning();
	//printf("\n%s\n", command);
}
void to_lower_case()
{
	//printf("\n%s", search_word);
	int counter = 0;
	while(counter < strlen(search_word))
	{
		search_word[counter] = tolower(search_word[counter]);
		counter++;
	}
	get_meaning_page();
}
void extract_meaning()
{
	printf("\nhi");
	char *char_pointer;
	char translation[100000], delimiter[2] = "=";
	int counter = 0;
	FILE *fp;
	fp = fopen(WORD_TRANSLATION , "r");
	fgets(translation, sizeof(translation), fp);
	char_pointer = strtok(translation, delimiter);
	printf("%s", translation);
	printf("\n char_pointer: %s\n", char_pointer);
	printf("hi");
	while(char_pointer != NULL)
	{
		counter++;
		char_pointer = strtok(NULL, delimiter);
		if(counter == 100)
		{
			strcpy(meaning_in_hindi, char_pointer);
			char_pointer = strtok(meaning_in_hindi, ">");
			counter = 0;
			while(char_pointer != NULL)
			{
				counter++;
				if(counter == 2)
				{
					strcpy(meaning_in_hindi, char_pointer);
					printf("hi");
					printf("%s", meaning_in_hindi);
					break;
				}
				char_pointer = strtok(NULL, ">");
			}
			break;
		}
	}
	fclose(fp);
}



*/












/*#include<stdio.h>
void main()
{
	printf("पूरा कर देना");
}
*/









/*#include<stdio.h>
#include<stdlib.h>
void main()
{
	char command[1000000];
	sprintf(command, "curl https://hindi.oneindia.com/dictionary/achieve-meaning-in-hindi/ > a.dat");
	system(command);
}*/


/*#include<stdio.h>
#include<stdlib.h>
void main()
{
	char command[1000000], search_word[20];
	printf("Enter any word to translate: ");
	gets(search_word);
	sprintf(command, "curl \"https://hindi.oneindia.com/dictionary/%s-meaning-in-hindi/\" > h.dat", search_word);
	system(command);
}*/
	//sprintf(command, "curl -s \"https://hindi.oneindia.com/dictionary/%s-meaning-in-hindi/\" > %s", search_word, WORD_TRANSLATION);
	//printf("\n%s\n", command);
	//system("curl https://hindi.oneindia.com/dictionary/achieve-meaning-in-hindi/ > aa.dat");
	//system(command);