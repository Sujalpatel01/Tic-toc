# Tic Tac Toe Game

This is a simple implementation of the classic Tic Tac Toe game in C. The game is played on a 3x3 grid where two players take turns marking the spaces in the grid with 'X' and 'O'. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row wins the game.

## How to Play

1. The game starts with player 'X'.
2. Players take turns entering the row and column numbers (0-2) to place their mark on the board.
3. The game checks for a win or a draw after each move.
4. The game ends when a player wins or the board is full (draw).

## Compilation and Execution

To compile and run the game on a Mac, follow these steps:

1. Open a terminal.
2. Navigate to the directory containing the `Tic-toc.c` file.
3. Compile the code using `gcc`:
    ```bash
    gcc Tic-toc.c -o tictactoe
    ```
4. Run the compiled program:
    ```bash
    ./tictactoe
    ```

## Code Structure

- `initializeBoard()`: Initializes the board with empty spaces.
- `printBoard()`: Prints the current state of the board.
- `checkWin()`: Checks if the current player has won.
- `isBoardFull()`: Checks if the board is full (draw).
- `makeMove(int row, int col)`: Makes a move on the board.
- `main()`: The main game loop.

## Example
0 1 2 0 | |
1 | |
2 | |

Player X's turn Enter row (0-2) and column (0-2): 0 0

0 1 2 0 X| |
1 | |
2 | |


