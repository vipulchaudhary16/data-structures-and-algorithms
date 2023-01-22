### [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/description/)

```cpp
class Solution {
public:
    bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0) return (arr[0] == target);
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool take = target >= arr[ind] ? f(ind-1, target - arr[ind], arr, dp) : false;
        bool notTake = f(ind-1, target, arr, dp);
        
        return dp[ind][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) { 
        int n = nums.size();
        int totalSum = 0;
        for(int i : nums) totalSum += i;
        if(totalSum % 2 != 0) return false;

        vector<vector<int>> dp (n, vector<int>((totalSum/2)+1, -1));
        return f(n-1, totalSum/2, nums, dp);
    }
};
```