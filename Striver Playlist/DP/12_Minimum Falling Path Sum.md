### [Minimum Falling Path Sum](https://leetcode.com/problems/minimum-falling-path-sum/)

```Recursive DP```
```cpp
class Solution {
public:
    int solve(int row, int col, vector<vector<int>> &matrix, int n, vector<vector<int>> &dp){
        if(col >= n or col < 0) return 1e9;
        if(row == n) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int direct_below = matrix[row][col] + solve(row+1,col,matrix,n, dp);
        int diag_left = matrix[row][col] + solve(row+1, col-1, matrix, n, dp);
        int diag_right = matrix[row][col] + solve(row+1,col+1,matrix,n, dp);
        
        return dp[row][col] = min(diag_right, min(diag_left, direct_below));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for(int i = 0; i < n; i++){
            ans = min(ans, solve(0,i,matrix,n, dp));
        }
        
        return ans;
    }
};
```

```Tabulation DP```

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        dp[n-1] = matrix[n-1];
        
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int direct_below = matrix[i][j] + dp[i+1][j];
                
                int diag_right = matrix[i][j];
                if(j+1 >= n) diag_right += 1e9;
                else diag_right += dp[i+1][j+1];
                
                int diag_left = matrix[i][j];
                if(j-1 < 0) diag_left += 1e9;
                else diag_left += dp[i+1][j-1];
                
                dp[i][j] = min(direct_below, min(diag_left, diag_right));
            }
        }
        
        int ans = INT_MAX;
        for(auto i : dp[0]){
            ans = min(ans, i);
            cout<<i<<" ";
        }
        
        return ans;
    }
};
```