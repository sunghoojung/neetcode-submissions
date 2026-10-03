class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minValue = numeric_limits<int>::max();

        for (int i = 0; i < prices.size(); i++) {
            minValue = min(minValue, prices[i]);
            int newProfit = prices[i] - minValue;
            profit = max(profit, newProfit);
        }
        return profit;
    }
};