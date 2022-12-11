## [Maximum Sum of Non-Adjacent Elements](https://leetcode.com/problems/house-robber/)

```Brute Force```

```cpp
class Solution {
public:
    int f(int ind, vector<int> nums){
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;
        
        int pick = nums[ind] + f(ind-2, nums);
        int notPick = f(ind-1, nums);
        
        return max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        return f(n-1, nums);
    }
};

/*
TC = O(2^n)
SC = O(n)
*/
```

```Recursive DP```

```cpp
class Solution {
public:
    int f(int ind, vector<int> nums, vector<int> &dp){
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int pick = nums[ind] + f(ind-2, nums, dp);
        int notPick = f(ind-1, nums, dp);
        
        return dp[ind] = max(pick, notPick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n-1, nums, dp);
    }
};

/*
TC = O(n)
SC = O(2n)
*/
```

```Tabulation DP```

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        
        dp[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            int take = nums[i];
            if(i > 1) take += dp[i-2];
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }
        
        return dp[n-1];
        
    }
};

/*
TC = O(n)
SC = O(n)
*/
```

```Space Optimization```

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        
        for(int i = 1; i < n; i++){
            int take = nums[i];
            if(i > 1) take += prev2;
            int notTake = prev;
            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
        
    }
};

/*
TC = O(n)
SC = O(1)
*/
```