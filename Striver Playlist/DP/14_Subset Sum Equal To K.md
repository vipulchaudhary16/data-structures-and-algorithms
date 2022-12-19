### [Subset Sum Equal To K](https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0)

```Recursive DP```

```cpp
#include <bits/stdc++.h> 

bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);
    if(dp[ind][target] != -1) return dp[ind][target];
    
    bool take = target >= arr[ind] ? f(ind-1, target - arr[ind], arr, dp) : false;
    bool notTake = f(ind-1, target, arr, dp);
    
    return dp[ind][target] = take || notTake;
    
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp (n, vector<int>(k+1, -1));
    return f(n-1, k, arr, dp);
}
```

```Tabulation DP```

```cpp
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp (n, vector<bool>(k+1, false));
    for(int i = 0; i < n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    
    for(int i = 1; i < n; i++){
        for(int target = 1; target <= k; target++){
            bool take = target >= arr[i] ? dp[i-1][target - arr[i]] : false;
            bool notTake = dp[i-1][target];
            dp[i][target] = take || notTake;
        }
    }
    
    return dp[n-1][k];
}
```

```Space Optimization```

```cpp
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, false), curr(k+1, false);
    //base case
    prev[0] = true; //whenever target is 0 we return true
    if(arr[0] <= k) prev[arr[0]] = true; //when ever target == arr[0] we return true;
    
    for(int i = 1; i < n; i++){
        for(int target = 1; target <= k; target++){
            bool take = target >= arr[i] ? prev[target - arr[i]] : false;
            bool notTake = prev[target];
            curr[target] = take || notTake;
        }
        prev = curr;
    }
    
    return prev[k];
}
```