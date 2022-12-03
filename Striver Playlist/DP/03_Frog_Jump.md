## [Frog Jump](https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0)

```Recursion & Memoization```

```cpp
#include <bits/stdc++.h> 
int solve(int n, vector<int> &height, vector<int> &dp){
    if(n == 0) return 0;
    
    if(dp[n] != -1) return dp[n];
    
    int left = solve(n-1, height, dp) + abs(height[n] - height[n-1]);
    int right = n > 1 ? solve(n-2, height, dp) + abs(height[n] - height[n-2]) : INT_MAX;
    
    return dp[n] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return solve(n-1, heights, dp); //0 based indexing so n-1
}
```

```Tabulation```

```cpp
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1);
    dp[0] = 0;
    
    for(int i = 1; i < n; i++){
        int fs = dp[i-1] + abs(heights[i-1] - heights[i]);
        int ss = i > 1 ? dp[i-2] + abs(heights[i-2] - heights[i]) : INT_MAX;
        dp[i] = min(fs, ss);
    }
    
    return dp[n-1];
}
```

```Space optimization```

```cpp
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0, prev2 = 0;
    
   for(int i = 1; i < n; i++){
       int fs = prev1 + abs(heights[i-1] - heights[i]);
       int ss = i > 1 ? prev2 + abs(heights[i-2] - heights[i]) : INT_MAX;
       int curr = min(fs, ss);
       prev2 = prev1;
       prev1 = curr;
   }
    return prev1;
}
```