//different libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

//different functions
//function to clear screen 
void cls ()
{
    int x;
    for (x = 0; x < 10; x++)
    {
        printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
}

//function to press enter
void PressEnterToContinue ()
{
    printf("Press enter to continue\n");
    char enter = 0;
    while (enter != '\r' && enter != '\n')
    {
        enter = getchar();
    }
}


//function to print the body that will be hanged with each mistake
void printBody(int mistakes, char* body) {
	printf("\tMistakes :%d\n", mistakes);
	switch(mistakes) {

		case 6: body[6] = '\\'; break;
		case 5: body[5] = '/'; break;
		case 4: body[4] = '\\'; break;
		case 3: body[3] = '|'; break;
		case 2: body[2] = '/'; break;
		case 1: body[1] = ')', body[0] = '('; break;
		default: break;

	}

	printf("\t _________\n"
	       "\t|         |\n"
	       "\t|        %c %c\n"
	       "\t|        %c%c%c\n"
	       "\t|        %c %c\n"
	       "\t|             \n"
	       "\t|             ", body[0], body[1], body[2],
	       body[3], body[4], body[5], body[6]);
}


//function to print the word and complete it each time the gamer guess a letter correctly
void printWord(char* guess, int len) {
	printf("\t");
	for (int i = 0; i < len; ++i)
	{
		printf("%c ", guess[i]);
	}
	printf("\n\n");
}


//function for the game loop for each level
void GameLoop(const char ChosenWord[15], int x ,int chance,int level)
{ int WordLength;
    WordLength = strlen(ChosenWord);
    printf("*******************************************\n\t\tHANGMAN-GAME\n*******************************************\n");
    printf("***LEVEL %d***\n\nThe Word to guess begun with ***%c*** and has ***%d*** caracters in it\n\n",level,x,WordLength);
    
	char *guessed = malloc(WordLength);
	char falseWord[chance];
	char *body = malloc(chance+1);

	memset(body, ' ', chance+1);
	memset(guessed, '_', WordLength);
	char guess;
	bool found;
	char* win;

	int mistakes = 0;
	setvbuf(stdin, NULL, _IONBF, 0);

	do {

		found = false;
		printf("\n\n");
		printBody(mistakes, body);
		printf("\n\n");
		printf("\tFalse Letters : ");
		if(mistakes == 0) printf("None\n");
		for (int i = 0; i < mistakes; ++i)
		{
			printf("%c", falseWord[i]);
		}
		printf("\n\n");
		printWord(guessed, WordLength);
		printf("\tGive me a alphabet in lower case : ");
		do {scanf("%c",&guess);} while ( getchar() != '\n' );
		for (int i = 0; i < WordLength; ++i)
		{
			if(ChosenWord[i] == guess) {
				found = true;
				guessed[i] = guess;
			}
		}
		if(!found) {
			falseWord[mistakes] = guess;
			mistakes += 1;
		}
		win = strchr(guessed, '_');
	}while(mistakes < chance && win != NULL);

	if(win == NULL) {
		printf("\n");
		printWord(guessed, WordLength);
		printf("\n\t*******Congrats! You have passed LEVEL %d : %s*******\n\n",level,ChosenWord);
		PressEnterToContinue ();
	} else {
		printf("\n");
		printBody(mistakes, body);
		printf("\n\n\tBetter try next time. Word was %s\n\n", ChosenWord);
	}

	free(body);
	free(guessed);  
}



//principal program
int main()
{
//declaring variables
    char start;
    int WordLength,i,number;
//INSERTING WORDS
char x1,x2,x3;
const char *WordsL1[] = { // array of pointers to constant strings__ fist level
        "hello","world","love","game", "welcome","money","like","best","old",
        "shoes","mind","beautiful","book","education","school","parents","doll",
        "words","purple","time","break","presentation","computer","fortune","amount" };
const char *WordsL2[] = { //array of words of second level 
        "pretty","carpet","war","eggs"," table","football","jump","pajama","puzzle",
        "pixel","cowboy","fake","joke","jaw","wizard","juicy","glasses","hurtful",
        "minute","accident","garbage","colorful","medium","blanket","emotions"};
const char *WordsL3[] = { //array of words of third level
        "syndrome","stylish","filthy","learning","converse","luxury","subway","awkward",
        "zombie","strength","psyche","gnostic","microwave","galaxy","transplant","oxygen",
        "length","stretch","joyful","rhythm","crypt","injury","envy","rainbow","scratch"};

   
   
   
   
   
    int table_size = 25; // size of each words arrays above
    srand(time(NULL)); // randomize the start value
    
    
    
    
    
    //STARTING THE GAME
    printf("*******************************************\n\t\tHANGMAN-GAME\n*******************************************\n");
    PressEnterToContinue ();
    printf("\nGAME Rules: \nObject: One player thinks of a word and the other tries to guess it by guessing letters.\nEach incorrect guess brings you closer to being hanged.\nTHERE ARE THREE DIFFENT LEVELS AND IN EACH LEVEL YOU HAVE ONE QUESTION TO ANSWER TO PASS TO THE NEXT LEVEL\n7 tries for Level1\n5 tries for Level2\n3 tries for Level3 \nGOOD LUCK !\n");
    PressEnterToContinue ();
    do
    {
        printf ("Start the game : yes(y) or no(n) ? ");
        scanf (" %c ", &start);
    }
    while((start=!'y')&&(start=!'n'));
    cls ();
    
    
    
    
    
    //GAME LOOP
    
    
    //FIRST LEVEL
    const char *ChosenWord1 = WordsL1[rand() % table_size]; //choosing randomly a word out of the array of strings
    x1=ChosenWord1[0]; //first letter of the chosen word
    GameLoop(ChosenWord1, x1 ,7,1); //we have 7 chances in level 1
    
   
	
	
	//SECOND LEVEL
	const char *ChosenWord2 = WordsL2[rand() % table_size]; //choosing randomly a word out of the array of strings
    x2=ChosenWord2[0]; //first letter of the chosen word
	GameLoop(ChosenWord2, x2 ,5,2); //we have 5 chances in level 2
	
	
	//THIRD LEVEL
	const char *ChosenWord3 = WordsL3[rand() % table_size]; //choosing randomly a word out of the array of strings
    x3=ChosenWord3[0]; //first letter of the chosen word
	GameLoop(ChosenWord3, x3 ,3,3); //we have 3 chances in level 3
	return EXIT_SUCCESS;
    
    
    
    
    return 0;
}


