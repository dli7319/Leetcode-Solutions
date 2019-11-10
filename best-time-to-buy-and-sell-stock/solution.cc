class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int lowest_price = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            max_profit = max(max_profit, prices[i]-lowest_price);
            lowest_price = min(lowest_price, prices[i]);
        }
        return max_profit;
    }
};
