### [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

```cpp
class Solution {
public:
    int solve(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(ind >= prices.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit;

        if(buy == 1) //we can buy here
        {
            int notBuy = solve(ind+1, 1, prices, dp);
            int buy = -prices[ind] + solve(ind+1, 0, prices, dp);
            profit = max(notBuy, buy);
        }

        if(buy == 0) //we can sell only
        {
            int notSell = solve(ind+1, 0, prices, dp);
            int sell = prices[ind] + solve(ind+2, 1,  prices, dp); //if we sell next day will be cool down so, ind + 2
            profit = max(notSell, sell);
        }

            return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));

        return solve(0, 1, prices, dp);
    }
};
```