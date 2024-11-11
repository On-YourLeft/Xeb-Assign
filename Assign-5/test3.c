#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define trimax 6

void lowa(char stringo[]);
void displayHangman(int tries);
void init(char guessWord[], int length);

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

    char mode[10];
    printf("\n\n\t\t\t\t\t\t\tWelcome to the Hangman Game! \n\tThe rules of this game are - There is a given word with ommited characters and you need to guess the characters to win the game. \n\t  You get limited chances only, use them wisely, don't mess it up, cause you don't wanna murder an imaginary person do you? \n\t\t\t\t\t\t   Now enough talk let's start the game. ");
    game:
    printf("\n\n\t\t\t\t   Now what mode do you wanna play this in Easy, Intermediate or Hard?\nEnter your choice : "); 
    fgets(mode ,sizeof(mode),stdin);
    lowa(mode);
    strtok(mode,"\n");

    struct WordandHint easywords[]={
            {"programming","Implementation of logic"},
            {"pizza","Popular italian dish"},
            {"hamburger","American'Freedommm'"},
            {"france","Revolution"}
        };
    struct WordandHint medwords[]={
            {"despacito","Spanish"},
            {"fahrenheit","American unit"},
            {"saxophone","Instrument"},
            {"lieutenant","High post"},
            {"cholestrol","Heart"}
        };
    struct Hardword hardwords[]={
            {"farhanitrate"},
            {"prerajulisation"},
            {"megatron"},
            {"quaff"},
            {"pneumonia"},

        };

    int wordCount=0;
    const char* secretWord;
    const char* hint = NULL;
    char displayWord[30];

    if (strcmp(mode, "easy") == 0) 
    {
        wordCount = sizeof(easywords) / sizeof(easywords[0]);
        int wordsIndex = rand() % wordCount;
        secretWord = easywords[wordsIndex].word;
        hint = easywords[wordsIndex].hint;
    } 
    else if (strcmp(mode, "intermediate") == 0) 
    {
        wordCount = sizeof(medwords) / sizeof(medwords[0]);
        int wordsIndex = rand() % wordCount;
        secretWord = medwords[wordsIndex].word;
        hint = medwords[wordsIndex].hint;
    } 
    else if (strcmp(mode, "hard") == 0)
    {
        wordCount = sizeof(hardwords) / sizeof(hardwords[0]);
        int wordsIndex = rand() % wordCount;
        secretWord = hardwords[wordsIndex].word;
    }
    else 
    {
        printf("Invalid mode selected. Please restart and choose easy, intermediate, or hard.\n");
        goto game;
    }

    caps(secretWord, displayWord);

    int wordLength = strlen(secretWord);
    char guess[wordLength + 1];
    init(guess, wordLength);

    int tries = 0; 
    char guessletter[26] = {0}; 
    int guessletterno = 0;

    if (hint!=NULL)
    {
        printf("\nHint for the word is : %s \n",hint);
    }

     while (tries < trimax) {
        printf("\nCurrent word: %s\n", guess);
        printf("Attempts left: %d\n", trimax - tries);
        displayHangman(tries);

        printf("Guessed letters: ");
        for (int i = 0; i < guessletterno; i++) {
            printf("%c ", guessletter[i]);
        }
        printf("\n");

        char guess;
        printf("Enter your guess (a single letter): ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        if (!isalpha(guess)) {
            printf("Invalid input. Please enter a letter.\n");
            continue;
        }

        int guessalr = 0;
        for (int i = 0; i < guessletterno; i++) {
            if (guessletter[i] == guess) {
                guessalr = 1;
                break;
            }
        }

        if (guessalr) 
        {
            printf("You've already guessed that letter.\n");
            continue;
        }

        guessletter[guessletterno++] = guess;

        int correctGuess = 0;
        for (int i = 0; i < wordLength; i++) {
            if (secretWord[i] == guess) {
                guess[i] = guess;
                correctGuess = 1;
            }
        }

        if (!correctGuess) {
            tries++;
            printf("Incorrect guess!\n");
        } else {
            printf("Good guess!\n");
        }

        if (strcmp(secretWord, guess) == 0) {
            printf("\nCongratulations! You've guessed the word: %s\n", secretWord);
            displayHangman(tries);
            return 0;
        }
    }

    printf("\nI'm sorry, but now you have the binary blood of this imaginative man on your hands. You're the culprit! The word was: %s\n", secretWord);
    displayHangman(tries);


    printf("You enjoyed this, didn't you? Wanna play again?");
    char againo[10];
    printf("\nState Yes or No:");
    fgets(againo ,sizeof(againo),stdin);
    lowa(againo);
    strtok(againo, "\n");
    
    if (strcmp(againo,"yes")==0)
    {
        goto game;
    }
    else
    {
        printf("\n\n\t\t\t\t\tNo problem, see you again someday.");
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

void displayHangman(int tries) {
    switch (tries) {
        case 0:
            printf("  +---+\n      |\n      |\n      |\n     ===\n");
            break;
        case 1:
            printf("  +---+\n  O   |\n      |\n      |\n     ===\n");
            break;
        case 2:
            printf("  +---+\n  O   |\n  |   |\n      |\n     ===\n");
            break;
        case 3:
            printf("  +---+\n  O   |\n /|   |\n      |\n     ===\n");
            break;
        case 4:
            printf("  +---+\n  O   |\n /|\\  |\n      |\n     ===\n");
            break;
        case 5:
            printf("  +---+\n  O   |\n /|\\  |\n /    |\n     ===\n");
            break;
        case 6:
            printf("  +---+\n  O   |\n /|\\  |\n / \\  |\n     ===\n");
            break;
    }
}

void init(char guess[], int length) {
    for (int i = 0; i < length; i++) {
        guess[i] = '_';
    }
    guess[length] = '\0';
}