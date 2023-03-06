### [Partition Array for Maximum Sum](https://leetcode.com/problems/partition-array-for-maximum-sum/description/)

```Recursive DP```
```cpp
class Solution {
public:
    int solve(int i, vector<int> &nums, int k, vector<int> &dp){
        int n = nums.size();
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int len = 0, maxEle = INT_MIN, maxAns = INT_MIN;
        for(int j = i; j < min(i+k, n); j++){
            len++;
            maxEle = max(maxEle, nums[j]);
            int sum = maxEle * len + solve(j+1, nums, k, dp);
            maxAns = max(maxAns, sum);
        }

        return dp[i] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, arr, k, dp);
    }
};
```

```Tabulation```
```cpp
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        
        for(int i = n-1; i >= 0; i--){
            int len = 0, maxEle = INT_MIN, maxAns = INT_MIN;
            for(int j = i; j < min(i+k, n); j++){
                len++;
                maxEle = max(maxEle, arr[j]);
                int sum = maxEle * len + dp[j+1];
                maxAns = max(maxAns, sum);
            }
            dp[i] = maxAns;
        }

        return dp[0];
    }
};
```