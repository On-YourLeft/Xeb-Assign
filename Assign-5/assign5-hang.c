#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

struct WordandHint
{
    char word[30];
    char hint[100];
};

int main()
{
    char mode[10];
    printf("\n\n\t\t\t\t\t\t\tWelcome to the Hangman Game! \n\tThe rules of this game are - There is a given word with ommited characters and you need to guess the characters to win the game. \n\t  You get limited chances only, use them wisely, don't mess it up, cause you don't wanna murder an imaginary person do you? \n\t\t\t\t\t\t   Now enough talk let's start the game. \n\n\t\t\t\t   Now what mode do you wanna play this in Easy, Intermediate or Hard?"); 
    fgets(mode ,sizeof(mode),stdin);
    lowa(mode);
    strtok(mode,"\n");
    if (strcmp(mode,"easy"))
    {
        struct WordandHint words[]={
        {"Programming","Implementation of logic"},
        {"Pizza","Popular italian dish"},
        {"",""}
        };
    }
}

void lowa(char stringo[])
{
    for (int i=0;stringo[i];i++)
    {
        stringo[i]=tolower(stringo[i]);
    }
}