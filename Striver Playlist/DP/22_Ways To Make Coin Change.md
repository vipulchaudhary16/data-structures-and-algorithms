### [Ways To Make Coin Change](https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0 )

```Recursive DP```

```cpp
#include<bits/stdc++.h>

long f(int ind, int tar, int * nums,  vector<vector<long>> &dp){
    if(ind == 0){
        if(tar % nums[0] == 0) return 1;
        return 0;
    }
    
    if(dp[ind][tar] != -1) return dp[ind][tar];
    
    long notTake = f(ind-1, tar, nums, dp);
    long take = 0;
    if(tar >= nums[ind]){
        take = f(ind, tar - nums[ind], nums, dp);
    }
    
    return dp[ind][tar] = take + notTake;
}

long countWaysToMakeChange(int *deno, int n, int value)
{
    vector<vector<long>> dp(n, vector<long> (value+1, -1));
    return f(n-1, value, deno, dp);
}
```

```Tabulation DP```

```cpp
#include<bits/stdc++.h>

long countWaysToMakeChange(int *nums, int n, int value)
{
    vector<vector<long>> dp(n, vector<long> (value+1, 0));
    for(int i = 0; i <= value; i++){
        if(i % nums[0] == 0) dp[0][i] = 1;
    }
    
    for(int ind = 1; ind < n; ind++){
        for(int tar = 0; tar <= value; tar++){
            long notTake = dp[ind-1][tar];
            long take = 0;
            if(tar >= nums[ind]){
                take = dp[ind][tar - nums[ind]];
            }
            dp[ind][tar] = take + notTake;
        }
    }
    
    return dp[n-1][value];
}
```