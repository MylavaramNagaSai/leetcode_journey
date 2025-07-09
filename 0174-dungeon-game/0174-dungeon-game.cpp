class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();

        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, INT_MAX));
        dp[rows][cols - 1] = 1;
        dp[rows - 1][cols] = 1;

        for (int i = rows - 1; i >= 0; --i) {
            for (int j = cols - 1; j >= 0; --j) {
                int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = max(1, need);
            }
        }

        return dp[0][0];
    }
};
