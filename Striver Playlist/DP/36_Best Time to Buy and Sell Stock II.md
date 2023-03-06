### [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/)

```Recursive DP```

```Cpp
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int buy, vector<int> &prices){
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        int profit;
        if(buy){
            int buy = -1 * prices[i] + solve(i+1, 0, prices);
            int notbuy = solve(i+1, 1, prices);
            profit = max(buy, notbuy);
        } else {
            int sell = prices[i] + solve(i+1, 1, prices);
            int notsell = solve(i+1, 0, prices);
            profit = max(sell, notsell);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        dp = vector<vector<int>> (prices.size(), vector<int>(2, -1));
        return solve(0, 1, prices);
    }
};
```


```Tabulation dp```

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // dp[n][0] = dp[n][1] = 0; //base case, no need to write

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                int profit;
                if(buy){
                    int buy = -1 * prices[i] + dp[i+1][0];
                    int notbuy = dp[i+1][1];
                    profit = max(buy, notbuy);
                } else {
                    int sell = prices[i] + dp[i+1][1];
                    int notsell = dp[i+1][0];
                    profit = max(sell, notsell);
                }

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }
};
```

```Space optimization```

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2,0);

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                int profit;
                if(buy){
                    int buy = -1 * prices[i] + ahead[0];
                    int notbuy = ahead[1];
                    profit = max(buy, notbuy);
                } else {
                    int sell = prices[i] + ahead[1];
                    int notsell = ahead[0];
                    profit = max(sell, notsell);
                }

                curr[buy] = profit;
            }
            ahead = curr;
        }

        return ahead[1];
    }
};
```