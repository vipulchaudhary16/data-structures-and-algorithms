# [Find N Unique Integers Sum up to Zero](https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/)

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        for(int i = 1; i <= n/2; i++)
        {
            ans.push_back(i);
            ans.push_back(-i);
        }
        if(n % 2 != 0) ans.push_back(0);
        return ans;
    }
};
```