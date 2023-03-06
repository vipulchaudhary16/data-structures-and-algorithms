### [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int profit = 0;

        for(int i = 1; i < prices.size(); i++){
            int cost = prices[i] - minPrice;
            profit = max(profit, cost);
            minPrice = min(minPrice, prices[i]); //this is dp, because we are keep tracking of past minimum price
        }

        return profit;
    }
};
```