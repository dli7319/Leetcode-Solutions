class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        // Profit if you buy
        vector<int> memo(prices);
        // Profit if you sell
        vector<int> memo2(prices);
        memo[0] = -prices[0];
        memo2[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            memo[i] = max(memo[i-1], memo2[i-1] - prices[i]);
            memo2[i] = max(memo2[i-1], memo[i-1] + prices[i]);
        }
        return memo2.back();
    }
};
