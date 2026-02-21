// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int max_profit = 0;
        int lowest = numeric_limits<int>::max();
        for (size_t i = 0; i < prices.size(); ++i) {
            lowest = min(lowest, prices[i]);
            max_profit = max(max_profit, prices[i] - lowest);
        }
        return max_profit;
    }
};
