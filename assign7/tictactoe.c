#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3

#define CROSS 1
#define CIRC -1
#define EMPTY 0

#define ONGOING 0
#define DRAW 2

int** init_board();
void free_board(int **board);
void print_board(int **board);
void get_player_move(int **board, int player);
int check_winner(int **board);

int main()
{
    int **board = init_board();
    int currentPlayer = CROSS;
    int gameState = ONGOING;
    int moves = 0;

    while (gameState == ONGOING && moves < 9)
    {
        print_board(board);
        if (currentPlayer == CROSS)
            printf("Player X's turn.\n");
        else
            printf("Player O's turn.\n");

        get_player_move(board, currentPlayer);
        moves++;
        gameState = check_winner(board);

        if (currentPlayer == CROSS) {
            currentPlayer = CIRC;
        } else {
            currentPlayer = CROSS;
        }
    }

    print_board(board);
    if (gameState == CROSS)
        printf("Player X wins!\n");
    else if (gameState == CIRC)
        printf("Player O wins!\n");
    else
        printf("The game is a draw!\n");

    free_board(board);
    board = NULL;

    return 0;
}

int** init_board()
{
    int **array = (int **) malloc(ROWS * sizeof(int *));
    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < ROWS; i++)
    {
        array[i] = (int *) calloc(COLS, sizeof(int));
        if (array[i] == NULL)
        {
            for(int j = 0; j < i; j++) free(array[j]);
            free(array);
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }
    return array;
}

void free_board(int **board)
{
    for (int i = 0; i < ROWS; i++)
    {
        free(board[i]);
    }
    free(board);
}

void print_board(int **a)
{
    printf("\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (a[i][j] == CIRC)
                printf(" O ");
            else if (a[i][j] == CROSS)
                printf(" X ");
            else
                printf("   ");

            if (j < COLS - 1)
                printf("|");
        }
        printf("\n");
        if (i < ROWS - 1)
            printf("---+---+---\n");
    }
    printf("\n");
}

void get_player_move(int **board, int player)
{
    while (true)
    {
        int row = -1, col = -1;
        printf("Enter row (0-2): ");
        scanf("%d", &row);
        printf("Enter col (0-2): ");
        scanf("%d", &col);

        if (row < 0 || row > 2 || col < 0 || col > 2)
        {
            printf("Invalid input. Coordinates must be 0, 1, or 2.\n");
            continue;
        }
        if (board[row][col] != EMPTY)
        {
            printf("That spot is already taken!\n");
            continue;
        }

        board[row][col] = player;
        break;
    }
}

int check_winner(int **board)
{
    for (int i = 0; i < ROWS; i++)
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];

    for (int j = 0; j < COLS; j++)
        if (board[0][j] != EMPTY && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return board[0][j];

    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ONGOING;
}

