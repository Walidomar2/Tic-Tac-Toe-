/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Walid Omar
 * @brief          : Contains the functionality of Tic-Tac-Toe game with 2 modes
                     single mode with computer and multi player mode.
 ******************************************************************************
 */

/* ----------------------------------------- Includes Section ---------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/* ----------------------------------------- Global Variables Section ---------------------------------- */
char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';

/* ----------------------------------------- Functions Declarations -----------------------------------------*/
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
char checkWinner();
void printWinner(char winFlag);
void player2_Move();
void computerMove();
void singlePlayerMode(void);
void multiPlayerMode(void);

/* ----------------------------------------- Main Function -----------------------------------------*/

int main()
{
    char mode;

    printf("Single Player Mode --> 1\n");
    printf("Multi player Mode  --> 2 \n");
    printf("Enter the game mode \n");
    scanf("%c",&mode);

    printf("\n******************************************************************\n");
    switch(mode){
        case '1': {singlePlayerMode(); break;}
        case '2': {multiPlayerMode(); break; }
        default :{printf("Invalid Input");}
    }

    return 0;
}






/* ----------------------------------------- Functions Implementation Section -----------------------------------------*/
void resetBoard()
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    int i;

    for (i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);

        if (i == 2)
            continue;

        printf("\n---|---|---\n");
    }
    printf("\n");
}

int checkFreeSpaces()
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return 1;
            }
        }
    }

    return 0;
}

void playerMove()
{
    char flag = 0;
    int rowNu;
    int colNu;

    do
    {

        printf("Enter row #(1-3): ");
        scanf("%d", &rowNu);
        if ((rowNu > 3) || (rowNu < 1))
        {
            printf("Invalid Row Number\n");
            flag = 1;
            continue;
        }
        rowNu--;

        printf("Enter column #(1-3): ");
        scanf("%d", &colNu);
        if ((colNu > 3) || (colNu < 1))
        {
            printf("Invalid Column Number\n");
            flag = 1;
            continue;
        }
        colNu--;

        if (board[rowNu][colNu] != ' ')
        {
            printf("Invalid Move\n");
            flag = 1;
        }
        else
        {
            board[rowNu][colNu] = PLAYER1;
            break;
        }
    } while (flag);
}

char checkWinner()
{
    int i;

    // check rows
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    // check column
    for (i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[1][1];
    }

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[1][1];
    }

    return ' ';
}

void printWinner(char winFlag)
{
    if (winFlag == 'X')
    {
        printf("X is the Winner\n");
    }
    else if (winFlag == 'O')
    {
        printf("O is the Winner\n");
    }
    else
    {
        printf("It's A Tie\n");
    }
}

void player2_Move()
{
    char flag = 0;
    int rowNu;
    int colNu;

    do
    {

        printf("Enter row #(1-3): ");
        scanf("%d", &rowNu);
        if ((rowNu > 3) || (rowNu < 1))
        {
            printf("Invalid Row Number\n");
            flag = 1;
            continue;
        }
        rowNu--;

        printf("Enter column #(1-3): ");
        scanf("%d", &colNu);
        if ((colNu > 3) || (colNu < 1))
        {
            printf("Invalid Column Number\n");
            flag = 1;
            continue;
        }
        colNu--;

        if (board[rowNu][colNu] != ' ')
        {
            printf("Invalid Move\n");
            flag = 1;
        }
        else
        {
            board[rowNu][colNu] = PLAYER2;
            break;
        }
    } while (flag);
}

void computerMove()
{
    srand(time(0));
    int rowNu;
    int colNu;

    if (checkFreeSpaces())
    {
        do
        {
            rowNu = rand() % 3;
            colNu = rand() % 3;

        } while (board[rowNu][colNu] != ' ');

        board[rowNu][colNu] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}

void singlePlayerMode(void)
{
    char winner = ' ';
    resetBoard();

    while ((winner == ' ') && (checkFreeSpaces() != 0))
    {
        printBoard();

        playerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }

        computerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
    }

    printBoard();
    printWinner(winner);
}

void multiPlayerMode(void)
{

    char winner = ' ';
    resetBoard();

    while ((winner == ' ') && (checkFreeSpaces() != 0))
    {
        printBoard();
        playerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }

        printBoard();
        player2_Move();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
    }

    printBoard();
    printWinner(winner);
}


