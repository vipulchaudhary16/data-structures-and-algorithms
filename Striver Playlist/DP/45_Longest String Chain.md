### [Longest String Chain](https://leetcode.com/problems/longest-string-chain/)

```cpp
bool cmp(string &s1, string &s2){
    return s1.size() < s2.size();
}

class Solution {
public:
    bool diffIsOne(string &s1, string &s2){
        int n = s1.size(), m = s2.size();
        if(n != m + 1) return false;
        
        int first = 0, second = 0;
        
        while(first < n){
            if(s1[first] == s2[second]){
                first++;
                second++;
            } else {
                first++;
            }
        }
        
        if(first == n and second == m) return true;
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        
        vector<int> dp(n, 1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(diffIsOne(words[i], words[j])){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        
        int ans = 0;
        for(int d : dp) ans = max(ans, d), cout<<d<<" ";
        
        return ans;
    }
};