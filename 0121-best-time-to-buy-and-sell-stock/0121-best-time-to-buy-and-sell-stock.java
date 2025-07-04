class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = Integer.MAX_VALUE;  // Track the lowest price so far
        int maxProfit = 0;                 // Track the max profit we can achieve

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;         // Update the lowest price
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice; // Update max profit
            }
        }

        return maxProfit;
    }
}
