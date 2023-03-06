### [Coin Change](https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0)


```Recursive DP```  

```cpp
#include <bits/stdc++.h> 

int f(int ind, int target, vector<int> &coins, vector<vector<int>> &dp){
    if(ind == 0){
        if(target % coins[0] == 0) return target/coins[0];
        return 1e9; //we want min result so to ignore this path
    }
    
    if(dp[ind][target] != -1) return dp[ind][target];
    
    int notTake = f(ind-1, target, coins, dp);
    int take = 1e9;
    if(coins[ind] <= target)
        take = 1 + f(ind, target - coins[ind], coins, dp);
    
    return dp[ind][target] = min(take, notTake);
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x+1, -1));
    int ans = f(n-1, x, num, dp);
    if(ans == 1e9) return -1;
    return ans;
}
```

```Tabulation DP```
```cpp
#include <bits/stdc++.h> 

int minimumElements(vector<int> &coins, int x)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(x+1, 0));
    
    for(int t = 0; t <=x; t++){
        if(t % coins[0] == 0) dp[0][t] = (t / coins[0]);
        else dp[0][t] = 1e9;
    }
    
    for(int ind = 1; ind < n; ind++){
        for(int target = 0; target <= x; target++){
            int notTake = dp[ind-1][target];
            int take = 1e9;
            if(coins[ind] <= target)
                take = 1 + dp[ind][target - coins[ind]];

            dp[ind][target] = min(take, notTake);
        }
    }
    
    return dp[n-1][x] == 1e9 ? -1 : dp[n-1][x];
}
```

```Space Optimization```
```cpp
#include <bits/stdc++.h> 

int minimumElements(vector<int> &coins, int x)
{
    int n = coins.size();
    vector<int> prev(x+1, 0), curr(x+1, 0);
    
    for(int t = 0; t <= x; t++){
        if(t % coins[0] == 0) prev[t] = (t / coins[0]);
        else prev[t] = 1e9;
    }
    
    for(int ind = 1; ind < n; ind++){
        for(int target = 0; target <= x; target++){
            int notTake = prev[target];
            int take = 1e9;
            if(coins[ind] <= target)
                take = 1 + curr[target - coins[ind]];

            curr[target] = min(take, notTake);
        }
        prev = curr;
    }
    
    return prev[x] == 1e9 ? -1 : prev[x];
}
```

```Space Optimization```

```cpp
#include<bits/stdc++.h>

long countWaysToMakeChange(int *nums, int n, int value)
{
    vector<long> prev(value+1, 0), curr(value+1, 0);
    for(int i = 0; i <= value; i++){
        if(i % nums[0] == 0) prev[i] = 1;
    }
    
    for(int ind = 1; ind < n; ind++){
        for(int tar = 0; tar <= value; tar++){
            long notTake = prev[tar];
            long take = 0;
            if(tar >= nums[ind]){
                take = curr[tar - nums[ind]];
            }
            curr[tar] = take + notTake;
        }
        prev = curr;
    }
    
    return prev[value];
}
```