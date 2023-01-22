### [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning/description/)

```cpp
class Solution {
public:
    bool isPalindrom(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    int solve(int i, string &s, vector<int> &dp){
        if(i == s.size()) return 0;

        if(dp[i] != -1)return dp[i];

        int mini = 1e9;
        for(int ind = i; ind < s.size(); ind++){
            if(isPalindrom(i, ind, s)){
                int cuts = 1 + solve(ind+1, s, dp);
                mini = min(mini, cuts);
            }
        }

        return dp[i] = mini;
    }
    int minCut(string s) {
        vector<int> dp(s.size(), -1);
        return solve(0, s, dp)-1;
    }
};
```