class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        // Step 1: Mark 'O's on borders and their connected 'O's as safe ('S')
        for (int i = 0; i < m; ++i) {
            dfs(board, i, 0, m, n);
            dfs(board, i, n - 1, m, n);
        }
        for (int j = 0; j < n; ++j) {
            dfs(board, 0, j, m, n);
            dfs(board, m - 1, j, m, n);
        }

        // Step 2: Flip all remaining 'O's to 'X', and 'S' back to 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';  // Surrounded
                } else if (board[i][j] == 'S') {
                    board[i][j] = 'O';  // Safe
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
            return;

        board[i][j] = 'S';  // Temporarily mark as safe
        dfs(board, i + 1, j, m, n);
        dfs(board, i - 1, j, m, n);
        dfs(board, i, j + 1, m, n);
        dfs(board, i, j - 1, m, n);
    }
};
