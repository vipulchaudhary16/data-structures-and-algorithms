### [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

```Recursive DP```

```cpp
class Solution {
public:
    int f(string& s1, string& s2, int ind1, int ind2,  vector<vector<int>>& dp){
        if(ind1<0 || ind2<0)
            return 0;

        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];

        if(s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + f(s1,s2,ind1-1,ind2-1,dp);

        else 
            return dp[ind1][ind2] = 0 + max(f(s1,s2,ind1,ind2-1,dp),f(s1,s2,ind1-1,ind2,dp));
   
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(text1,text2,n-1,m-1,dp);
    }
};

/*
TC : O(n * m)
SC : O(n * m) + O(stack space)
*/
```

```Tabulation DP```

```cpp
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){

            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];

            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
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
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        vector<int> prev(m+1,0), curr(m+1, 0);

        for(int i = 0; i <= n; i++) prev[0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){

            if(s1[i-1] == s2[j-1])
                curr[j] = 1 + prev[j-1];

            else 
                curr[j] = max(prev[j], curr[j-1]);
            }

            prev = curr;
        }

        return prev[m];
    }
};
```

