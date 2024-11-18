//Tic-Tac-Toe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define size 5

void lowa(char stringo[]);
void boardprint(char board[size][size]);

int main()
{
    char board[size][size];
    int winner=0;

    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            board[i][j] = ' ';
        }
    }

    printf("\n\n\t\t\t\t\t\t\tWelcome to the game of Tic-Tac-Toe! \n\nThe working of this game has the following components:\n1. Objective: To be the first to make a straight line with either 'X' or 'O'.\n2. Game Board: The board consists of a 3x3 matrix-like structure, having 9 small boxes.\n3. You win by making your symbol in a row or diagonal or column. Also, as a prt of strategy you need to block your opponent from forming a straight line while making of your own.\n\n\t\t\t\t\t\t   Now enough talk let's start the game. \n\n");
    selection:
    printf("Choose a mode in which you wanna play the game, Single player(single) or Two player(double?)");
    char mode[10];
    printf("\nEnter your choice:");
    fgets(mode,sizeof(mode),stdin);
    strtok(mode,"\n");
    lowa(mode);

    if (strcmp(mode,"single")==0)
    {

    }
    else if (strcmp(mode,"double")==0)
    {

    }
    else
    {
        printf("\n\nError! Enter a valid choice!");
        goto selection;
    }

    boardprint(board);
}

void lowa(char stringo[])
{
    for (int i=0;stringo[i];i++)
    {
        stringo[i]=tolower(stringo[i]);
    }
}

void boardprint(char board[size][size])
{
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            printf(" %c",board[i][j]);
            if (j<size-1)
            {
                printf(" |");
            }
        }
        printf("\n");   
        if (i<size-1)
        {
            for (int k=0;k<size;k++)
            {
                printf("---");
                if (k<size-1)
                {
                    printf("+");
                }
            }
            printf("\n");
        }
    }
}