### [Unique Paths](https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0)


```Recursive DP```
```cpp
#include <bits/stdc++.h> 

int solve(int i, int j, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int up = solve(i-1, j, dp);
    int left = solve(i, j-1, dp);
    return dp[i][j] = (up + left);
}

int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>> dp(m+1, vector<int> (n+1,-1));
    return solve(m-1, n-1, dp);
}

/*
TC : O(n*m)
SC : O(n-1) + O(m-1) + O(n*m)
       Stack space     
*/
```

```Tabulation DP```

```cpp
#include <bits/stdc++.h> 

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m+1, vector<int> (n+1,0));
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 and j == 0) dp[0][0] = 1;
            else {
                int left = 0, up = 0;
                if(i > 0) left = dp[i-1][j];
                if(j > 0) up = dp[i][j-1];
                dp[i][j] = left + up;
            } 
        }
    }
    return dp[m-1][n-1];
}

/*
TC : O(n*m)
SC : O(n*m)
*/
```

```Space Optimization```

```cpp
#include <bits/stdc++.h> 

int uniquePaths(int m, int n) {
    vector<int> prev(n,0);
    prev[0] = 1;
    
    for(int i = 0; i < m; i++){
        vector<int> curr(n,0);
        
        for(int j = 0; j < n; j++){
            if(i == 0 and j == 0) {
                curr[j] = 1;
            } else {
                int left = 0, up = 0;
                if(j > 0) left = curr[j-1];
                if(i > 0) up = prev[j];
                curr[j] = left + up;
            }
        }
        prev = curr;
    }
    
    return prev[n-1];
}

/*
TC : O(n*m)
SC : O(n)    
*/
```