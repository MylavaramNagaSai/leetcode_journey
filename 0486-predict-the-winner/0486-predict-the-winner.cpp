#include <vector>
#include <numeric>

class Solution {
public:
    /**
     * @brief Determines if Player 1 can win the game.
     * @param nums A vector of integers representing the numbers in the game.
     * @return True if Player 1 can win, false otherwise.
     */
    bool predictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        
        // dp[i][j] will store the maximum score the current player can get
        // over the opponent in the subarray nums[i...j].
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));

        // Base case: If there is only one number (i == j), the current
        // player takes it. The score difference is simply that number.
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }

        // Fill the DP table. We iterate based on the length of the subarray.
        // len = 1 is the base case, so we start from len = 2.
        for (int len = 2; len <= n; ++len) {
            // 'i' is the starting index of the subarray.
            for (int i = 0; i <= n - len; ++i) {
                // 'j' is the ending index of the subarray.
                int j = i + len - 1;
                
                // Choice 1: Take nums[i]. The new score difference will be
                // nums[i] minus the score difference the *other* player gets
                // from the remaining subarray nums[i+1...j].
                int choice_i = nums[i] - dp[i + 1][j];
                
                // Choice 2: Take nums[j]. The new score difference will be
                // nums[j] minus the score difference the *other* player gets
                // from the remaining subarray nums[i...j-1].
                int choice_j = nums[j] - dp[i][j - 1];
                
                // The player chooses the option that maximizes their score difference.
                dp[i][j] = std::max(choice_i, choice_j);
            }
        }

        // The result for the entire game is stored in dp[0][n-1].
        // Player 1 wins if their final score is >= Player 2's score,
        // which means the score difference is >= 0.
        return dp[0][n - 1] >= 0;
    }
};