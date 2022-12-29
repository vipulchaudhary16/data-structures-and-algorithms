### [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/description/)

```Recursive DP```

```cpp
class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        //i -> index of pattern, j -> index of string
        if(i < 0 and j < 0) return true; //patern and string dono khatam ho gya
        if(i < 0 and j >= 0) return false; //pattern khatam ho gya, but string baaki h
        if(i >= 0 and j < 0){ //string khatam ho gya but pattern baaki h, to sab * hone chahie
            for(int ii = 0; ii <= i; ii++)
                if(p[ii] != '*') return false;
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[j] == p[i] or p[i] == '?') return dp[i][j] = solve(i-1, j-1, s, p, dp); //agar same char hai ya pattern me ? hai to match mil gya to aage badho
        if(p[i] == '*') return dp[i][j] = solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp); //ek baar * ko nothing lo aur ek baar * ke comparison me string ka ek char pass karao
        
        return dp[i][j] = false; //last me to false hi aayega
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, s, p, dp);
    }
};
```

```Tabulation DP```

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, 0));
        
        dp[0][0] = true;
        for(int i = 1; i <= n; i++ ) dp[0][i] = false;
        for(int i = 1; i <= m; i++){
            bool flag = true;
            for(int ii = 1; ii <= i; ii++)
                if(p[ii-1] != '*') {
                    flag = false;
                    break;
                }
            dp[i][0] = flag;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[j-1] == p[i-1] or p[i-1] == '?') dp[i][j] = dp[i-1][j-1]; 
                else if(p[i-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = false; //last me to false hi aayega
            }
        }

        return dp[m][n];
    }
};
```