### [Minimum Number of Deletions and Insertions](https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
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

int canYouMake(string &str, string &ptr)
{
    int l1 = str.size(), l2 = ptr.size();
    int lcs = longestCommonSubsequence(str, ptr);
    return (l1 + l2 - 2*lcs);
}
```

[Leetcode link](https://leetcode.com/problems/delete-operation-for-two-strings/description/)