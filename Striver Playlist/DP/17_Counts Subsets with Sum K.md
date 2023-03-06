### [Counts Subsets with Sum K](https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0)


```Recursive DP```

```cpp
int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(ind == 0){
          if(target==0 && arr[0]==0) return 2;
          else if(arr[0]==target || target==0) return 1;
          else return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = f(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = f(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken + taken;
}
```

```Tabulation DP```

```cpp
#include <bits/stdc++.h> 
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, 0));
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    if(num[0] <= tar) dp[0][num[0]] = 1;
    if(num[0] == 0) dp[0][0] = 2;
    
    for(int i = 1; i < n; i++){
        for(int target = 0; target <= tar; target++){
            int notTaken = dp[i-1][target];
            int taken = 0;
            if(num[i]<=target)
                taken = dp[i-1][target-num[i]];
        
            dp[i][target]= notTaken + taken;
        }
    }
    
    return dp[n-1][tar];
}
```

```Space Optimization```

```cpp
#include <bits/stdc++.h> 
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar+1, 0), curr(tar+1, 0);
    prev[0] = 1;
    if(num[0] <= tar) prev[num[0]] = 1;
    if(num[0] == 0) prev[0] = 2;
    
    for(int i = 1; i < n; i++){
        for(int target = 0; target <= tar; target++){
            int notTaken = prev[target];
            int taken = 0;
            if(num[i]<=target)
                taken = prev[target-num[i]];
        
            curr[target]= notTaken + taken;
        }
        prev = curr;
    }
    
    return prev[tar];
}
```