//Rock Paper Scissors game

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void lowa(char stringo[]);
int game(char player[], char compi[]);

int main()
{
    printf("\n\n\t\t\t\tWelcome to the game of Rock, Paper and Scissors!\n\tThe rules of this game are pretty simple, Rock beats Scissors, Scissors beat Paper, and Paper beats Rock.\n\t   Quite simple, isn't it? As long as you don't consider the rock as 'THE ROCK', you're well and good.\n\t\t\tNow enough talk let's start the game, you ready to lose?\n");
    char namo[50];
    printf("\nBefore the game begins, state your name Warrior : ");
    fgets(namo ,sizeof(namo),stdin);
    strtok(namo,"\n");

    srand(time(NULL));
    
    int rounds=1,compwin=0,userwin=0,draw=0;

    play: 

    printf("\nOkay, be ready.\n");
    for (int i=3;i>0;i--)
    {
        sleep(1);
        printf("%d ",i);
    }
    sleep(1);
    printf("\nGo!!!\n");
    printf("Rock, Paper or Scissors?\nEnter your choice : ");
    char userc[10];
    fgets(userc ,sizeof(userc),stdin);
    lowa(userc);
    strtok(userc,"\n");
    
    int compo=rand()%100;
    
    char *compc;
    if (compo>=0 && compo<=33)
    {
        compc= "rock";
    }
    else if (compo>=34 && compo<=66)
    {
        compc= "paper";
    }
    else if (compo>=67 && compo<=100)
    {
        compc= "scissors";
    }
    
    printf("\nYou chose : %s",userc);
    printf("\nI chose : %s",compc);
    int result=game(userc,compc);
    if (result==-1)
    {
        printf("\n\nIts a draw. :|");
        draw+=1;
    }
    else if (result==0)
    {
        printf("\n\nI won!!!!!\nSorry %s, but you lose. :(",namo);
        compwin+=1;
    }
    else if (result==1)
    {
        printf("\n\nYou won!\n\nCongratulations %s, Human evolution is still possible. :) ",namo);
        userwin +=1;
    }
    printf("\nRounds we played - %d",rounds);
    printf("\nRounds you won - %d",userwin);
    printf("\nRounds I won - %d",compwin);
    printf("\nRounds that were draw - %d",draw);
    rounds += 1;
    printf("\n\nEnjoyed this little game of ours? Wanna try your luck again?");
    char againo[10];
    printf("\nState Yes or No:");
    fgets(againo ,sizeof(againo),stdin);
    lowa(againo);
    strtok(againo, "\n");
    

    if (strcmp(againo,"yes")==0)
    {
        goto play;
    }
    else
    {
        printf("\n\n\t\t\t\t\tNo problem warrior, see you again someday.");
    }
    return 0;    
}

int game(char player[], char compi[])
{
    if (strcmp(player, compi) == 0) 
    { return -1; }

    else if (strcmp(player, "rock") == 0 && strcmp(compi, "paper") == 0) 
    { return 0; }
    
    else if (strcmp(player, "paper") == 0 && strcmp(compi, "scissors") == 0) 
    { return 0; }
    
    else if (strcmp(player, "scissors") == 0 && strcmp(compi, "rock") == 0) 
    { return 0; }

    else if (strcmp(player, "paper") == 0 && strcmp(compi, "rock") == 0) 
    { return 1; }
    
    else if (strcmp(player, "scissors") == 0 && strcmp(compi, "paper") == 0) 
    { return 1; }
    
    else if (strcmp(player, "rock") == 0 && strcmp(compi, "scissors") == 0) 
    { return 1; }

}

void lowa(char stringo[])
{
    for (int i=0;stringo[i];i++)
    {
        stringo[i]=tolower(stringo[i]);
    }
}