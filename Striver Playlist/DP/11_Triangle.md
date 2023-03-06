### [Triangle](https://leetcode.com/problems/triangle/)

```Recursive DP```

```cpp
class Solution {
public:
    int n;
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i == n-1) return triangle[i][j]; //if we have reached last row that is our destination
        
        if(dp[i][j] != -1) return dp[i][j]; 
        
        int down = triangle[i][j] + f(i+1, j, triangle, dp); //move to down in next row
        int diag_right = triangle[i][j] + f(i+1, j+1, triangle, dp); //move to diagonally right to next row
        
        return dp[i][j] = min(down, diag_right);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1)); //longest row is nth row, and it as n+1 elements
        return f(0,0,triangle, dp);
    }
};
```

```Tabulation DP```

```cpp
class Solution {
public:
    int n;    
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -0)); //longest row is nth row, and it as n elements
        
        dp[n-1] = triangle[n-1];
        
        for(int i = n-2; i >= 0; i--){
            for(int j = triangle[i].size()-1; j >= 0 ; j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diag_right = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, diag_right);
            }
        }
        
        return dp[0][0];
    }
};
```

```Space Optimization```

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n, 0);
        for(int i = 0; i < n; i++) prev[i] = triangle[n-1][i];
        
        for(int i = n-2; i >= 0; i--){
            vector<int> curr(n,0);
            for(int j = i; j >= 0; j--){
                int down = triangle[i][j] + prev[j];
                int diag = triangle[i][j] + prev[j+1];
                curr[j] = min(down, diag);
            }
            prev = curr;
        }
        
        return prev[0];
    }
};
```