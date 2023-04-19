### [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;

        unordered_map<char, int> mp;
        int ans = INT_MIN, l = 0, r = 0;

        while(r < s.size()){
            if(mp.count(s[r])) l = max(l, mp[s[r]]+1);
            mp[s[r]] = r;
            ans = max(ans, (r-l+1));
            r++;
        }

        return ans;
    }
};
```