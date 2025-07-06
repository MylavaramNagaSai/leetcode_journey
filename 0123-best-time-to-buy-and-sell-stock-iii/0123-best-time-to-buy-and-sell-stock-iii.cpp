class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> left(n, 0);  // Max profit if we sell on or before day i
        vector<int> right(n, 0); // Max profit if we buy on or after day i

        // Forward pass: max profit up to day i
        int minPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            minPrice = min(minPrice, prices[i]);
            left[i] = max(left[i - 1], prices[i] - minPrice);
        }

        // Backward pass: max profit from day i to end
        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            right[i] = max(right[i + 1], maxPrice - prices[i]);
        }

        // Combine the two profits
        int maxProfit = 0;
        for (int i = 0; i < n; ++i) {
            maxProfit = max(maxProfit, left[i] + right[i]);
        }

        return maxProfit;
    }
};
