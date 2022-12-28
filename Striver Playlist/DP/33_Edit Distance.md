### [Edit Distance](https://leetcode.com/problems/edit-distance/description/)

```Recursive DP```

```cpp
class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = solve(i-1, j-1, s1, s2, dp);
        else {
            int insert = solve(i, j-1, s1, s2, dp); //s1 ke pichhe ek char insert kar denge so i (s1 ka pointer) to waha hi rahega
            int _delete = solve(i-1, j, s1, s2, dp); //s1 ka char delete karenge to fir j (s2 ka pointer to waha hi rahega kyu ki match nhi mila iisi liye to remove kiya na)
            int replace = solve(i-1, j-1, s1, s2, dp); //jo replace kar diya to jis char ki need thi ussi se replace karenge na, to dono pointer change honge
            
            return dp[i][j] = 1 + min({insert, _delete, replace}); //ek operation karenge tino me se aur aage badhenge
        }
    }
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, s1, s2, dp);
    }
};
```

```Tabulation DP```

```cpp
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <=m; j++){
                if(i == 0) dp[i][j] = j; //base case
                if(j == 0) dp[i][j] = i; //base case
                
                if(i != 0 and j != 0){ // i = 0 and j = 0 is base case so,
                    if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                    else {
                        int insert = dp[i][j-1]; 
                        int _delete = dp[i-1][j]; 
                        int replace = dp[i-1][j-1];
                        dp[i][j] = 1 + min({insert, _delete, replace});
                    }
                }
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
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <=m; j++){
                if(i == 0) curr[j] = j; //base case
                if(j == 0) curr[j] = i; //base case
                
                if(i != 0 and j != 0){ // i = 0 and j = 0 is base case so,
                    if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1];
                    else {
                        int insert = curr[j-1]; 
                        int _delete = prev[j]; 
                        int replace = prev[j-1];
                        curr[j] = 1 + min({insert, _delete, replace});
                    }
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};
```