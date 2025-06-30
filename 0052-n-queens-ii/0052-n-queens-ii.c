#include <stdlib.h>
#include <math.h>

void solve(int n, int row, int* queens, int* count) {
    if (row == n) {
        (*count)++;
        return;
    }

    for (int col = 0; col < n; ++col) {
        int safe = 1;
        for (int i = 0; i < row; ++i) {
            if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
                safe = 0;
                break;
            }
        }
        if (safe) {
            queens[row] = col;
            solve(n, row + 1, queens, count);
        }
    }
}

int totalNQueens(int n) {
    int count = 0;
    int* queens = (int*)malloc(sizeof(int) * n);
    solve(n, 0, queens, &count);
    free(queens);
    return count;
}
