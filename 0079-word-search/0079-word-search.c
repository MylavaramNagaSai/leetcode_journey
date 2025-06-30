#include <stdbool.h>
#include <string.h>

bool dfs(char** board, int boardSize, int* boardColSize, int i, int j, char* word, int index, bool** visited) {
    if (word[index] == '\0') return true;
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize[0]) return false;
    if (visited[i][j] || board[i][j] != word[index]) return false;

    visited[i][j] = true;
    bool found =
        dfs(board, boardSize, boardColSize, i+1, j, word, index+1, visited) ||
        dfs(board, boardSize, boardColSize, i-1, j, word, index+1, visited) ||
        dfs(board, boardSize, boardColSize, i, j+1, word, index+1, visited) ||
        dfs(board, boardSize, boardColSize, i, j-1, word, index+1, visited);

    visited[i][j] = false;
    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int rows = boardSize, cols = boardColSize[0];
    bool** visited = (bool**)malloc(rows * sizeof(bool*));
    for (int i = 0; i < rows; i++) {
        visited[i] = (bool*)calloc(cols, sizeof(bool));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (dfs(board, rows, boardColSize, i, j, word, 0, visited)) {
                for (int r = 0; r < rows; r++) free(visited[r]);
                free(visited);
                return true;
            }
        }
    }

    for (int r = 0; r < rows; r++) free(visited[r]);
    free(visited);
    return false;
}
