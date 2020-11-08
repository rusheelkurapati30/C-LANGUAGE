// Program to convert english word to hindi meaning.

/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define WORD_TRANSLATION "dictionary.dat"
void get_meaning_page();
void extract_meaning();
char meaning_in_hindi[50];
char search_word[50], command[1000000];
void main()
{
	printf("\nEnter the word to convert from english to hindi: ");
	fgets(search_word, sizeof(search_word), stdin);
	search_word[strlen(search_word) - 1] = '\0';
	get_meaning_page();
	extract_meaning();
	if(meaning_in_hindi != '\0')
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
	sprintf(command, "\"view-source:https://hindi.oneindia.com/dictionary/%s-meaning-in-hindi/\" > %s", search_word, WORD_TRANSLATION);
	//printf("\n%s\n", command);
	system(command);
	//printf("\n%s\n", command);

}
void extract_meaning()
{
	char *char_pointer;
	char translation[1000000], delimiter[2] = "<";
	int counter = 0;
	FILE *fp;
	fp = fopen(WORD_TRANSLATION , "r");
	fgets(translation, sizeof(translation), fp);
	char_pointer = strtok(translation, delimiter);
	while(char_pointer != NULL)
	{
		counter++;
		char_pointer = strtok(NULL, delimiter);
		if(counter == 800)
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











































#include<stdio.h>
#include<stdlib.h>
void main()
{
	//system("url \"view-source:https://hindi.oneindia.com/dictionary/Achieve-meaning-in-hindi/\"> dictionary.dat");
	system("\"START view-source:https://hindi.oneindia.com/dictionary/Achieve-meaning-in-hindi\" > dictionary.dat");
	//system("START http://google.com");
}