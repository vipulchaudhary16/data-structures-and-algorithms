### [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/)

```Recursive DP```

```cpp
class Solution {
public:
    int solve(int ind, int buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(k == 0) return 0;
        if(ind == prices.size()) return 0;

        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];

        int profit;
        if(buy==1){
            int buy = -1 * prices[ind] + solve(ind+1, 0, k, prices, dp);
            int notBuy = solve(ind+1, 1, k, prices, dp);
            profit = max(buy, notBuy);
        } else {
            int sell = prices[ind] + solve(ind+1, 1, k - 1, prices, dp);
            int notSell = solve(ind+1, 0, k, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[ind][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k+1, -1)));
        return solve(0, 1, k, prices, dp);

    }
};
```