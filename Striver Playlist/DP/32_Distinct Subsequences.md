### [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)

```Recursive DP```

```cpp
class Solution {
public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]) return dp[i][j] = solve(i-1, j-1, s, t, dp) + solve(i-1, j, s, t, dp);
        else return dp[i][j] = solve(i-1, j, s, t, dp);
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1,m-1,s,t,dp);
    }
};          
```

```Tabulation DP```

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
        
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][m];
    }
};
```

```Space Optimization```

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> dp(m+1, 0), curr(m+1,0);
        
        dp[0] = 1;
        curr[0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]) curr[j] = dp[j-1] + dp[j];
                else curr[j] = dp[j];
            }
            dp = curr;
        }
        
        return dp[m];
    }
};
```

```More space optimization🫡```

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> dp(m+1, 0);
        
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = m; j >= 1; j--)
                if(s[i-1] == t[j-1]) dp[j] = dp[j-1] + dp[j];
        }
        
        return dp[m];
    }
};
```