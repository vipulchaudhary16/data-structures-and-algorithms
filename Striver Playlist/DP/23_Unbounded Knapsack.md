### [Unbounded Knapsack](https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0)

```Recursive DP```

```cpp
#include <bits/stdc++.h> 
int solve(int ind, int w, vector<int> &weight, vector<int> &profit, vector<vector<int>> &dp){
    if(ind == 0){
        return (w / weight[0]) * profit[0];
    }
    
    if(dp[ind][w] != -1) return dp[ind][w];
    
    int notTake = solve(ind-1, w, weight, profit, dp);
    int take = -1e9;
    if(weight[ind] <= w) take = profit[ind] + solve(ind, w - weight[ind], weight, profit, dp);
    
    return dp[ind][w] = max(notTake, take);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return solve(n-1, w, weight, profit, dp);
}

```

```Tabulation DP```

```cpp
#include <bits/stdc++.h> 

int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    
    for(int wt = weight[0]; wt <= W; wt++){
        dp[0][wt] = (int)(wt / weight[0]) * profit[0];
    }
    
    for(int ind = 1; ind < n; ind++){
        for(int w = 0; w <= W; w++){
            int notTake = dp[ind-1][w];
            int take = -1e9;
            if(weight[ind] <= w) take = profit[ind] + dp[ind][w - weight[ind]];

            dp[ind][w] = max(notTake, take);
        }
    }
    
    return dp[n-1][W];
}
```

```Space optimization```

```cpp
#include <bits/stdc++.h> 

int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<int> prev(W+1, 0), curr(W+1, 0);
    
    for(int wt = weight[0]; wt <= W; wt++){
        prev[wt] = (int)(wt / weight[0]) * profit[0];
    }
    
    for(int ind = 1; ind < n; ind++){
        for(int w = 0; w <= W; w++){
            int notTake = prev[w];
            int take = -1e9;
            if(weight[ind] <= w) take = profit[ind] + curr[w - weight[ind]];

            curr[w] = max(notTake, take);
        }
        prev = curr;
    }
    
    return prev[W];
}

```