### [Stock Buy And Sell](https://leetcode.com/653p42
roblems/best-time-to-buy-and-sell-stock/description/)
 mc3s
* find min price and max profit every time

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0], profit = 0;

        for(int price : prices){
            int cost = price - minPrice;
            profit = max(profit, cost);
            minPrice = min(minPrice, price);
        }

        return profit;
    }
};
```