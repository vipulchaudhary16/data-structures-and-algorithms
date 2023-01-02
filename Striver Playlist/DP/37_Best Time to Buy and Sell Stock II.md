### [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/)

```
Recursive DP
```

```cpp
class Solution {
public:
    int solve(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(cap == 0) return 0;
        if(ind == prices.size()) return 0;

        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        int profit;
        if(buy){
            //we are able to buy
            int buy = -1 * prices[ind] + solve(ind+1, 0, cap, prices, dp);
            int notBuy = solve(ind+1, 1, cap, prices, dp);
            profit = max(buy, notBuy);
        } else {
            //we are able to sell, we completed one transaction so cap - 1
            int sell = prices[ind] + solve(ind +1 , 1, cap-1, prices, dp);
            int notSell = solve(ind+1, 0, cap, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //3d dp, [n][2][3] , [size][buyornot][capacity]
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return solve(0, 1, 2, prices, dp);
    }
};
```

```Tabulation```

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));

        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){//cap 0 is base case
                    int profit;
                    if(buy){
                        int buy = -1 * prices[ind] + dp[ind+1][0][cap];
                        int notBuy = dp[ind+1][1][cap];
                        profit = max(buy, notBuy);
                    } else {
                        int sell = prices[ind] + dp[ind+1][1][cap-1];
                        int notSell = dp[ind+1][0][cap];
                        profit = max(sell, notSell);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};
```

```Space Optimization```
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int> (3, 0));
        vector<vector<int>> curr(2, vector<int> (3, 0));

        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    int profit;
                    if(buy){
                        int buy = -1 * prices[ind] + after[0][cap];
                        int notBuy = after[1][cap];
                        profit = max(buy, notBuy);
                    } else {
                        int sell = prices[ind] + after[1][cap-1];
                        int notSell = after[0][cap];
                        profit = max(sell, notSell);
                    }
                    curr[buy][cap] = profit;
                }
            }
            after = curr;
        }
        return after[1][2];
    }
};
```