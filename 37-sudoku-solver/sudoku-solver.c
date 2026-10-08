#include <stdbool.h>

bool solve(char** board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {

            if (board[row][col] != '.')
                continue;

            for (char num = '1'; num <= '9'; num++) {
                bool valid = true;

                // Check row
                for (int j = 0; j < 9; j++) {
                    if (board[row][j] == num) {
                        valid = false;
                        break;
                    }
                }

                if (!valid)
                    continue;

                // Check column
                for (int i = 0; i < 9; i++) {
                    if (board[i][col] == num) {
                        valid = false;
                        break;
                    }
                }

                if (!valid)
                    continue;

                // Check 3 x 3 box
                int startRow = (row / 3) * 3;
                int startCol = (col / 3) * 3;

                for (int i = startRow; i < startRow + 3; i++) {
                    for (int j = startCol; j < startCol + 3; j++) {
                        if (board[i][j] == num) {
                            valid = false;
                            break;
                        }
                    }

                    if (!valid)
                        break;
                }

                if (valid) {
                    board[row][col] = num;

                    if (solve(board))
                        return true;

                    // Backtrack
                    board[row][col] = '.';
                }
            }

            return false;
        }
    }

    return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board);
}