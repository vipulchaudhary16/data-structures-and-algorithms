### [Print Longest Common Subsequence](https://www.youtube.com/watch?v=-zI4mrF2Pb4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=27)

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

        int i = n, j = m;
        string ans = "";

        while(i > 0 and j > 0){
            if(s1[i-1] == s2[j-1]){
                ans += s1[i-1];
                i--, j--;
            } else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            } else {
                j--;
            }
        }

        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;
        return dp[n][m];
    }
};
```