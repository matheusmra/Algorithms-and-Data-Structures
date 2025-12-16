class Solution {
    public int maxProfit(int[] prices) {
        int buyPrice = prices[0];   
        int maxProfit = 0;
        for (int i = 1; i < prices.length; i++) {
            int profit = prices[i] - buyPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
            if (prices[i] < buyPrice) {
                buyPrice = prices[i];
            }
        }
        return maxProfit;
    }
}
