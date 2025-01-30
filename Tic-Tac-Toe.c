#include <stdio.h>

// Define the board and the current player
char board[3][3];
char currentPlayer;

// Function to initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X'; // X always starts first
}

// Function to print the current state of the board
void printBoard() {
    printf("  0 1 2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("  -----\n");
    }
}

// Function to check if the current player has won
int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return 1;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return 1;
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return 1;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return 1;
    return 0;
}

// Function to check if the board is full (draw)
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

// Function to make a move
int makeMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
        return 0;
    
    board[row][col] = currentPlayer;
    return 1;
}

int main() {
    int row, col;
    int gameOver = 0;
    
    initializeBoard();
    
    while (!gameOver) {
        printBoard();
        printf("\nPlayer %c's turn\n", currentPlayer);
        printf("Enter row (0-2) and column (0-2): ");
        scanf("%d %d", &row, &col);
        
        if (makeMove(row, col)) {
            if (checkWin()) {
                printBoard();
                printf("\nPlayer %c wins!\n", currentPlayer);
                gameOver = 1;
            }
            else if (isBoardFull()) {
                printBoard();
                printf("\nGame is a draw!\n");
                gameOver = 1;
            }
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        else {
            printf("\nInvalid move! Try again.\n");
        }
    }
    
    return 0;
}