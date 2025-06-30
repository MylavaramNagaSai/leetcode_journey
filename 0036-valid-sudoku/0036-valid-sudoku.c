#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int rows[9][9] = {0};
    int cols[9][9] = {0};
    int boxes[9][9] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;

            int num = board[i][j] - '1';  // convert '1'-'9' → 0–8
            int boxIndex = (i / 3) * 3 + (j / 3);

            if (rows[i][num]++ > 0) return false;
            if (cols[j][num]++ > 0) return false;
            if (boxes[boxIndex][num]++ > 0) return false;
        }
    }

    return true;
}
