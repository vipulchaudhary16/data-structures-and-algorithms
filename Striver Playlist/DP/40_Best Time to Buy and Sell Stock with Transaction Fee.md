### [Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

```cpp
class Solution {
public:
    vector<vector<int>> dp;
    int fees;
    int solve(int i, int buy, vector<int> &prices){
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        int profit;
        if(buy){
            int buy = -1 * prices[i] + solve(i+1, 0, prices);
            int notbuy = solve(i+1, 1, prices);
            profit = max(buy, notbuy);
        } else {
            int sell = -1 * fees + prices[i] + solve(i+1, 1, prices);
            int notsell = solve(i+1, 0, prices);
            profit = max(sell, notsell);
        }

        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        fees = fee;
        dp = vector<vector<int>> (prices.size(), vector<int>(2, -1));
        return solve(0, 1, prices);
    }
};
```