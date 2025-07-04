class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;

        // Loop through the array and accumulate profit from all ascending pairs
        for (int i = 1; i < prices.length; i++) {
            // If the price goes up, we take the profit
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
}
