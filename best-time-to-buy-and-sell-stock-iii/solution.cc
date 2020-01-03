class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return false;
        vector<vector<vector<int>>> memo(2);
        // first index 0,...,prices.size()-1 time
        // second index 0,1,2 transactions completed
        // third index 0,1 stocks held
        memo[0] = vector<vector<int>>(3, vector<int>(2));
        memo[1] = vector<vector<int>>(3, vector<int>(2));
        memo[0][1][1] = -prices[0];
        memo[0][1][0] = 0;
        memo[0][2][1] = INT_MIN;
        memo[0][2][0] = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            memo[1][1][1] = max(memo[0][1][1], -prices[i]);
            memo[1][1][0] = max(memo[0][1][0], memo[0][1][1] + prices[i]);
            memo[1][2][1] = max(memo[0][2][1], memo[0][1][0] - prices[i]);
            memo[1][2][0] = max(memo[0][2][0], memo[0][2][1] + prices[i]);
            std::swap(memo[0], memo[1]);
        }
        int maxProfit = max(0, memo[0][1][0]);
        maxProfit = max(maxProfit, memo[0][2][0]);
        return maxProfit;
    }
};
