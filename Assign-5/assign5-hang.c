//Hangman Game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define trimax 5

void lowa(char stringo[]);
void init(char guess[], int length);
void showhang(int tries);


struct WordandHint
{
    char word[30];
    char hint[100];
};

struct Hardword
{
    char word[30];
};

int main()
{
    srand(time(NULL));

    char mode[20];
    printf("\n\n\t\t\t\t\t\t\tWelcome to the Hangman Game! \n\tThe rules of this game are - There is a given word with ommited characters and you need to guess the characters to win the game. \n\t  You get limited chances only, use them wisely, don't mess it up, cause you don't wanna murder an imaginary person do you? \n\t\t\t\t\t\t   Now enough talk let's start the game. ");

    int rounds = 1;
    int wino=0;

    game:
    printf("\n\n\t\t\t\t   Now what mode do you wanna play this in Easy, Intermediate or Hard?\nEnter your choice : "); 
    scanf(" %s",mode);
    lowa(mode);

    struct WordandHint easywords[]=
    {
        {"programming","Implementation of logic"},
        {"pizza","Popular italian dish"},
        {"hamburger","American'Freedommm'"},
        {"france","Revolution"}
    };
    struct WordandHint medwords[]=
    {
        {"despacito","Spanish"},
        {"fahrenheit","American unit"},
        {"saxophone","Instrument"},
        {"lieutenant","High post"},
        {"cholestrol","Heart"}
    };
    struct Hardword hardwords[]=
    {
        {"farhanitrate"},
        {"prerajulisation"},
        {"megatron"},
        {"quaff"},
        {"pneumonia"},
    };

    int wordcount=0;
    const char* secretword;
    const char* hint = NULL;
    char displayword[30];

    if (strcmp(mode,"easy")==0)
    {
        wordcount = sizeof(easywords)/sizeof(easywords[0]);
        int wordindex = rand()% wordcount;
        secretword = easywords[wordindex].word;
        hint = easywords[wordindex].hint;
    }

    else if(strcmp(mode,"intermediate")==0)
    {
        wordcount = sizeof(medwords)/sizeof(medwords[0]);
        int wordindex = rand()% wordcount;
        secretword = medwords[wordindex].word;
        hint = medwords[wordindex].hint;
    }

    else if (strcmp(mode,"hard")==0)
    {
        wordcount = sizeof(hardwords)/sizeof(hardwords[0]);
        int wordindex = rand() % wordcount;
        secretword = hardwords[wordindex].word;
    }

    else 
    {
        printf("Invalid mode selected, please choose easy, intermediate or hard.\n");
        goto game;
    }

    int wordlength = strlen(secretword);
    char guesso[wordlength + 1];
    init(guesso, wordlength);

    int tries = 0;
    char guessletter[26] = {0};
    int guessletterno = 0;

    if (hint != NULL)
    {
        printf("\nHint for the word is : %s \n",hint);
    }

    while (tries<trimax)
    {
        printf("\nThe Word : %s",guesso);
        printf("\nAttempts left : %d",trimax-tries);
        showhang(tries);

        printf("Guessed letter: ");
        for (int i=0; i<guessletterno;i++)
        {
            printf("%c  ",guessletter[i]);
        }
        printf("\n");

        char guess;
        printf("Enter your guess (a single letter) : ");
        scanf(" %c",&guess);
        guess = tolower(guess);

        if (!isalpha(guess)) 
        {
            printf("Invalid input. Please enter a letter.\n");
            continue;
        }

        int guessalr = 0;
        for (int i=0;i<guessletterno;i++)
        {
            if (guessletter[i]==guess)
            {
                guessalr=1;
                break;
            }
        }

        if (guessalr)
        {
            printf("\nYou've already guessed that letter.\n");
            continue;
        }

        guessletter[guessletterno++] = guess;

        int correctguess = 0;
        for (int i=0; i <wordlength;i++)
        {
            if (secretword[i] == guess)
            {
                guesso[i] = guess;
                correctguess = 1;
            }
        }

        if (!correctguess)
        {
            tries++;
            printf("\nIncorrect guess!\n");
        }
        else
        {
            printf("\nGood guess!\n");
        }

        if (strcmp(secretword,guesso)==0)
        {
            printf("\nCongratulations! You've guessed the word : %s",secretword);
            wino++;
            showhang(tries);
            printf("\n\nThe number of rounds you played : %d",rounds);
            printf("\n\nThe number of rounds you won : %d",wino);
            rounds++;
            break;
        }
    }
    
        if (strcmp(secretword,guesso)!=0)
        {
            printf("\nI'm sorry, but now you have the binary blood of this imaginative man on your hands. You're the culprit!\n\nThe word was: %s",secretword);
            showhang(tries);
            printf("\n\nThe number of rounds you played : %d",rounds);
            printf("\n\nThe number of rounds you won : %d",wino);
            rounds++;
        }

        printf("\n\n\t\t\t\t\tYou enjoyed this, didn't you? Wanna play again?");
        char againo[10];
        printf("\nState yes or no : ");
        scanf(" %s",againo);
        strtok(againo,"\n");
        lowa(againo);

        if (strcmp(againo,"yes")==0)
        {
            goto game;
        }
        else
        {
            printf("\n\n\t\t\t\t\t\tNo problem, see you again someday.");
        }

    return 0;
}

void lowa(char stringo[])
{
    for (int i=0;stringo[i];i++)
    {
        stringo[i]=tolower(stringo[i]);
    }
}

void init(char guess[], int length)
{
    for (int i=0; i<length;i++)
    {
        guess[i] = '_';
    }
    guess[length] = '\0';
}

void showhang(int tries)
{
    switch (tries)
    {
        case 0:
            printf(" \n+-----+\n      |\n      |\n      |\n     ===\n");
            break;
        case 1:
            printf(" \n+-----+\n  O   |\n      |\n      |\n     ===\n");
            break;
        case 2:
            printf(" \n+-----+\n  O   |\n  |   |\n      |\n     ===\n");
            break;
        case 3:
            printf(" \n+-----+\n  O   |\n /|   |\n      |\n     ===\n");
            break;
        case 4:
            printf(" \n+-----+\n  O   |\n /|\\  |\n      |\n     ===\n");
            break;
        case 5:
            printf(" \n+-----+\n  O   |\n /|\\  |\n / \\  |\n     ===\n");
            break;
    }
}