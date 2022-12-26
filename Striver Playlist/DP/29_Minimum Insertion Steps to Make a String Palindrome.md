### [Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/)

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

    int minInsertions(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        return s.length() - longestCommonSubsequence(s1, s);
    }
};
```