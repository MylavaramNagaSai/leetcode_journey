#include <stdlib.h>
#include <string.h>

void addSolution(char*** result, int* returnSize, int** returnColumnSizes, int* queens, int n) {
    char** board = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; ++i) {
        board[i] = (char*)malloc(n + 1);
        memset(board[i], '.', n);
        board[i][n] = '\0';
        board[i][queens[i]] = 'Q';
    }

    result[*returnSize] = board;
    (*returnColumnSizes)[*returnSize] = n;
    (*returnSize)++;
}

int isSafe(int* queens, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void solve(int n, int row, int* queens, char*** result, int* returnSize, int** returnColumnSizes) {
    if (row == n) {
        addSolution(result, returnSize, returnColumnSizes, queens, n);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solve(n, row + 1, queens, result, returnSize, returnColumnSizes);
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    int maxSolutions = 1000;
    char*** result = (char***)malloc(sizeof(char**) * maxSolutions);
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxSolutions);
    *returnSize = 0;

    int* queens = (int*)malloc(sizeof(int) * n);
    solve(n, 0, queens, result, returnSize, returnColumnSizes);
    free(queens);

    return result;
}
