//Tic-Tac-Toe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>


void lowa(char stringo[]);
void boardprint(char **board, int size);

int main()
{
    int winner=0,size;

    printf("\n\n\t\t\t\t\t\t\tWelcome to the game of Tic-Tac-Toe! \n\nThe working of this game has the following components:\n1. Objective: To be the first to make a straight line with either 'X' or 'O'.\n2. Game Board: The board consists of a nxn matrix-like structure, having n^2 small boxes, for eg, a 3x3 matrix will have 9 boxes.\n3. You win by making your symbol in a row or diagonal or column. Also, as a prt of strategy you need to block your opponent from forming a straight line while making of your own.\n\n\t\t\t\t\t\t   Now enough talk let's start the game. \n\n");
    printf("\nWhat board size do you want to play in? (Eg. Input 3 for 3x3, 4 for 4x4...)\nEnter your choice : ");
    scanf("%d",&size);

    char **board = (char**)malloc(size * sizeof(char *));
    for (int i=0;i<size;i++)
    {
        board[i]=(char*)malloc(size * sizeof(char));
        for (int j=0;j<size;j++)
        {
            board[i][j] = ' ';
        }
    }

    selection:
    printf("\n\nChoose a mode in which you wanna play the game, Single player(single) or Two player(double?)");
    char mode[10];
    printf("\nEnter your choice : ");
    scanf(" %s",mode);
    lowa(mode);

    if (strcmp(mode,"single")==0)
    {
        printf("\nBoard size is : %d x %d",size,size);
        printf("\nSingle Player mode initialising");
        for(int i=0;i<3;i++)
        {
            sleep(1);
            printf(".");
        }
        sleep(1);
        printf("\nLet's start: \n\n");

    }
    else if (strcmp(mode,"double")==0)
    {
        printf("\nBoard size is : %d x %d",size,size);
        printf("\nDouble Player mode initialising");
        for(int i=0;i<3;i++)
        {
            sleep(1);
            printf(".");
        }
        sleep(1);
        printf("\nStart the game: \n\n");

    }
    else
    {
        printf("\n\nError! Enter a valid choice!\n");
        goto selection;
    }

    boardprint(board,size);
    for (int i = 0; i < size; i++) 
    {
        free(board[i]);
    }
    free(board);

    return 0;
}

void lowa(char stringo[])
{
    for (int i=0;stringo[i];i++)
    {
        stringo[i]=tolower(stringo[i]);
    }
}

void boardprint(char **board, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %c", board[i][j]);
            if (j < size - 1) {
                printf(" |");
            }
        }
        printf("\n");
        if (i < size - 1) {
            for (int k = 0; k < size; k++) {
                printf("---");
                if (k < size - 1) {
                    printf("+");
                }
            }
            printf("\n");
        }
    }
}
