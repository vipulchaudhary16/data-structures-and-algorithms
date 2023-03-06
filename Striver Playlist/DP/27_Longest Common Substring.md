### [Longest Common Substring](https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1)

```Tabulation DP```

```cpp
#include <bits/stdc++.h> 
int lcs(string &s1, string &s2){
	int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    
    for(int i = 0; i < n; i++) dp[i][0] = 0;
    for(int i = 0; i < m; i++) dp[0][i] = 0;
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            } else dp[i][j] = 0;
        }
    }
    
    return ans;
}
```