## [House Robber II](https://leetcode.com/problems/house-robber-ii/)

```cpp
class Solution {
public:
    int f(int ind, vector<int> nums, vector<int> &dp){
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int pick = nums[ind] + f(ind - 2, nums, dp);
        int notPick = f(ind-1, nums, dp);
        
        return dp[ind] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        vector<int> ignoreFirst, ignoreLast;
        int n = nums.size();
        
        if(n == 1) return nums[0];
        
        for(int i = 0; i < n; i++){
            if(i != 0) ignoreFirst.push_back(nums[i]);
            if(i != n -1) ignoreLast.push_back(nums[i]);
        }
        
        vector<int> dp(n, -1);
        int ans1 = f(n-2,ignoreLast, dp);
        dp = vector<int> (n, -1);
        int ans2 = f(n-2, ignoreFirst, dp);
        
        return max(ans1, ans2);
    }
};
```