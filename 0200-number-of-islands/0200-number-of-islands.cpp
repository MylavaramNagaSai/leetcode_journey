class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // Boundary and water check
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != '1')
            return;

        grid[i][j] = '0'; // Mark as visited

        // Visit all 4 directions
        dfs(grid, i - 1, j); // up
        dfs(grid, i + 1, j); // down
        dfs(grid, i, j - 1); // left
        dfs(grid, i, j + 1); // right
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j); // Sink the island
                }
            }
        }

        return count;
    }
};
