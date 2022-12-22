### [0 1 Knapsack](https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0)


```Recursive DP```

```cpp
#include <bits/stdc++.h> 
int f(int ind, int w, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp){
    if(ind == 0){
        if(w >= weight[0]) return value[0];
        return 0;
    }
    
    if(dp[ind][w] != -1) return dp[ind][w];
    
    int notTake = f(ind-1, w, weight, value, dp);
    int take =  weight[ind] > w ? -1e8 : value[ind] + f(ind-1, w - weight[ind], weight, value, dp);
    
    return dp[ind][w] = max(take, notTake);
    
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
    return f(n-1, maxWeight, weight, value, dp);
}
```

```Tabulation```

```cpp
#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
    for(int i = weight[0]; i <= maxWeight; i++) dp[0][i] = value[0]; //base case
    
    for(int ind = 1; ind < n; ind++){
        for(int w = 0; w <= maxWeight; w++){
            int notTake = dp[ind-1][w];
            int take = w >= weight[ind] ? value[ind] + dp[ind-1][w - weight[ind]] : -1e8;
            dp[ind][w] = max(take, notTake);
        }
    }
    
    return dp[n-1][maxWeight];
}
```

```Space Optimization```

```cpp
#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);
    for(int i = weight[0]; i <= maxWeight; i++) prev[i] = value[0]; //base case
    
    for(int ind = 1; ind < n; ind++){
        for(int w = 0; w <= maxWeight; w++){
            int notTake = prev[w];
            int take = w >= weight[ind] ? value[ind] + prev[w - weight[ind]] : -1e8;
            curr[w] = max(take, notTake);
        }
        prev = curr;
    }
    
    return prev[maxWeight];
}
```