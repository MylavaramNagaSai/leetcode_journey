int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = *gridColSize;

    // Use the grid itself as the DP array to save space
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue; // start point
            else if (i == 0) grid[i][j] += grid[i][j - 1]; // first row
            else if (j == 0) grid[i][j] += grid[i - 1][j]; // first column
            else grid[i][j] += (grid[i - 1][j] < grid[i][j - 1]) ? grid[i - 1][j] : grid[i][j - 1];
        }
    }

    return grid[m - 1][n - 1];
}
