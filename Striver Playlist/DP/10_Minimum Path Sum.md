### [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)

```Recursive DP```

```cpp
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 and j == 0) return grid[i][j];
        if(i < 0 or j < 0) return 1000000;
        if(dp[i][j] != -1) return dp[i][j];
        int up = grid[i][j] + solve(i-1, j, grid, dp);
        int left = grid[i][j] + solve(i, j-1, grid, dp);
        return dp[i][j] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        return solve(m-1, n-1, grid, dp);
    }
};
```

```Tabulation DP```

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 and j == 0) {
                    dp[0][0] = grid[0][0];
                } else {
                    int left = 1000000, up = 1000000;
                    if(i > 0) up = grid[i][j] + dp[i-1][j];
                    if(j > 0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(up, left);
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};
```

```Space optimization```

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); //rows
        int n = grid[0].size(); //cols
        
        vector<int> prev(n, 0); //previous row values
        
        for(int i = 0; i < m; i++){
            
            vector<int> curr(n,0); //current row values
            for(int j = 0; j < n; j++){
                if(i == 0 and j == 0) {
                    curr[0] = grid[0][0];
                } else {
                    int left = 1000000, up = 1000000;
                    if(i > 0) up = grid[i][j] + prev[j]; //up, so look for prev row
                    if(j > 0) left = grid[i][j] + curr[j-1]; //left so look for curr row
                    curr[j] = min(up, left);
                }
            }
            prev = curr; //curr row will be prev row for next iteration
        }
        
        return prev[n-1]; //answer will be stored at col - 1 
    }
};
```