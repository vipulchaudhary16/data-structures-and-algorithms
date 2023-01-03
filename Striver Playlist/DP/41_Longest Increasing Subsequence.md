### [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/description/)

```Recursive DP```

```cpp
class Solution {
public:
    int solve(int curr_ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp){
        if(curr_ind == nums.size()) return 0;

        if(dp[curr_ind][prev_ind+1] != -1) return dp[curr_ind][prev_ind+1];

        int notTake = solve(curr_ind + 1, prev_ind, nums, dp);

        int take = 0;
        if(prev_ind == -1 or nums[curr_ind] > nums[prev_ind])
            take = 1 + solve(curr_ind + 1, curr_ind, nums, dp);

        return dp[curr_ind][prev_ind+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //we need to have n + 1, because prev ind has value -1 which will be saved as -1 + 1 = 0
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, nums, dp);
    }
};
```