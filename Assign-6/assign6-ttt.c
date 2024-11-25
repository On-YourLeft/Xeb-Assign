//Tic-Tac-Toe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void lowa(char stringo[]);
void boardprint(char **board, int size);
int check_winner(char **board, int size);
int is_draw(char **board, int size);
void singleplayergame(char **board, int size, char *playername);
void doubleplayergame(char **board, int size);
void initialize_board(char **board, int size) ;

int main()
{
    int size;    
    char *name = (char*)malloc(sizeof(char));

    printf("\n\n\t\t\t\t\t\t\tWelcome to the game of Tic-Tac-Toe! \n\nThe working of this game has the following components:\n1. Objective: To be the first to make a straight line with either 'X' or 'O'.\n2. Game Board: The board consists of a nxn matrix-like structure, having n^2 small boxes, for eg, a 3x3 matrix will have 9 boxes.\n3. You win by making your symbol in a row or diagonal or column. Also, as a prt of strategy you need to block your opponent from forming a straight line while making of your own.\n\n\t\t\t\t\t\t   Now enough talk let's start the game. \n\n");
    
    printf("\nWhat board size do you want to play in? (Eg. Input 3 for 3x3, 4 for 4x4...)\nEnter your choice : ");
    scanf(" %d",&size);

    char **board = (char**)calloc(size, sizeof(char *));
    for (int i=0;i<size;i++)
    {
        board[i]=(char*)calloc(size, sizeof(char));
        for (int j=0;j<size;j++)
        {
            board[i][j] = ' ';
        }
    }

    initialize_board(board, size);

    selection:
    initialize_board(board, size);
    printf("\n\nChoose a mode in which you wanna play the game\n1. V/S Computer (type-single)\n2. Two player(type-double)");
    char mode[10];
    printf("\nEnter your choice : ");
    scanf(" %s",mode);
    lowa(mode);

    if (strcmp(mode,"single")==0)
    {
        printf("State your name player : ");
        scanf(" %s",name);

        printf("\nBoard size is : %d x %d",size,size);
        printf("\nSingle Player mode initialising");
        for(int i=0;i<3;i++)
        {
            sleep(1);
            printf(".");
        }
        sleep(1);
        printf("\nLet's start: \n\n");
        singleplayergame(board,size,name);
        char againo[10];
        printf("\n\nEnjoyed it, didn't you?");
        printf("\nShould we play again? Yes or No : ");
        scanf(" %s",againo);
        lowa(againo);
        if (strcmp(againo,"yes")==0)
        {
            for (int i = 0; i < size; i++) 
            {
                free(board[i]);
            }
            free(board);
            board = (char **)calloc(size, sizeof(char *));
            for (int i = 0; i < size; i++) 
            {
                board[i] = (char *)calloc(size, sizeof(char));
                for (int j = 0; j < size; j++) 
                {
                    board[i][j] = ' ';  
                }
            }
            goto selection;
        }
        else if (strcmp(againo,"no")==0)
        {
            for (int i = 0; i < size; i++) 
            {
                free(board[i]);
            }
            free(board);
            printf("\n\n\t\t\t\t\t\t   Goodbye.");
        }
        
        else
        {
            printf("\n\nError! Enter a valid choice!\n");
            goto selection;
        }

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
        doubleplayergame(board,size);
        char againo[10];
        printf("\n\nShould we play again? Yes or No : ");
        scanf("%s",againo);
        lowa(againo);
        if (strcmp(againo,"yes")==0)
        {
            for (int i = 0; i < size; i++) 
            {
                free(board[i]);
            }
            free(board);
            board = (char **)calloc(size, sizeof(char *));
            for (int i = 0; i < size; i++) 
            {
                board[i] = (char *)calloc(size, sizeof(char));
                for (int j = 0; j < size; j++) 
                {
                    board[i][j] = ' ';  
                }
            }
            goto selection;
        }
        else if (strcmp(againo,"no")==0)
        {
            for (int i = 0; i < size; i++) 
            {
                free(board[i]);
            }
            free(board);
            printf("\n\n\t\t\t\t\t\t   Goodbye.");
        }
        
        else
        {
            printf("\n\nError! Enter a valid choice!\n");
            goto selection;
        }
    }
    //boardprint(board,size);
    for (int i = 0; i < size; i++) 
    {
        free(board[i]);
    }
    free(board);
    free(name);

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
    
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            printf(" %c", board[i][j]);
            if (j < size - 1) 
            {
                printf(" |");
            }
        }
        printf("\n");
        if (i < size - 1) 
        {
            for (int k = 0; k < size; k++) 
            {
                printf("---");
                if (k < size - 1) 
                {
                    printf("+");
                }
            }
            printf("\n");
        }
    }
}

int check_winner(char **board,int size)
{
    for (int i=0;i<size;i++)
    {
        int win=1;
        for (int j=1;j<size;j++)
        {
            if (board[i][j] != board[i][0] || board[i][0] == ' ')
            {
                win=0;
                break;
            }
        }
        if (win)
        {
            return board[i][0];
        }
    }

    for (int i=0;i<size;i++)
    {
        int win=1;
        for (int j=1;j<size;j++)
        {
            if (board[j][i] != board[0][i] || board[j][i]==' ')
            {
                win=0;
                break;
            }
        }
        if(win)
        {
            return board[0][i];
        }
    }

    int win=1;
    for (int i=1;i<size;i++)
    {
        if (board[i][i] != board[0][0] || board[i][i] == ' ')
        {
            win =0;
            break;
        }
    }
    if(win)
    {
        return board[0][0];
    }

    win =1;
    for (int i=1;i<size;i++)
    {
        if (board[i][size-i-1] != board[0][size-1] || board[i][size - i - 1]==' ')
        {
            win = 0;
            break;
        }
    }
    if (win)
    {
        return board[0][size - 1];
    }

    return 0;
}

int is_draw(char **board, int size)
{
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            if (board[i][j]==' ')
            return 0;
        }
    }
    return 1;
}

void singleplayergame(char **board, int size, char *playername) 
{
    
    int player = 1;
    char playerchoice = 'X', computerchoice = 'O';
    int row, col;
    
    while (1) 
    {
        if (player == 1) 
        {
            boardprint(board, size);
            printf("\nYour turn %s!\nEnter row and column (e.g., 2 3): ", playername);
            scanf(" %d %d", &row, &col);
            row--;
            col--;

            if (row >= 0 && col >= 0 && col < size && row < size && board[row][col] == ' ') 
            {
                board[row][col] = playerchoice;
                player = 2;
            } 
            else
            {
                printf("\n\nInvalid move, try again.\n");
                continue;
            }
        } 
        else 
        {
            boardprint(board, size);
            printf("\n\nMy turn...\n\n");
            do 
            {
                row = rand() % size;
                col = rand() % size;
            } 
            while (board[row][col] != ' ');
            board[row][col] = computerchoice;
            player = 1;
        }


        int winner = check_winner(board, size);
        if (winner) 
        {
            printf("%s (%c) wins the game!\n",playername,winner);
            break;
        }
        if (is_draw(board, size)) 
        {
            printf("\nSadly it's a draw!\n");
            break;
        }
    }
    boardprint(board, size);
}

void doubleplayergame(char **board, int size) 
{
    int player = 1;
    char symbols[2] = {'X', 'O'};
    int row, col;
    
    while (1) 
    {
        boardprint(board, size);
        printf("\n\nPlayer %d (%c)! Enter row and column (e.g., 2 3): ", player, symbols[player - 1]);
        scanf("%d %d", &row, &col);
        row--;
        col--;

        if (row >= 0 && row < size && col >= 0 && col < size && board[row][col] == ' ') 
        {
            board[row][col] = symbols[player - 1];
            player = 3 - player;
        } 
        else 
        {
            printf("Invalid move! Try again.\n");
            continue;
        }


        int winner = check_winner(board, size);
        if (winner) 
        {
            printf("Player %d (%c) wins!\n", winner == 'X' ? 1 : 2, winner);
            break;
        }

        if (is_draw(board, size)) 
        {
            printf("It's a draw!\n");
            break;
        }
    }
    boardprint(board, size);
}

void initialize_board(char **board, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            board[i][j] = ' ';
        }
    }
}