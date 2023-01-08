### [Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/)

```cpp
class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,1), cnt(n,1);
        
        int maxi = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i] and dp[i] < 1+dp[j]){
                    dp[i] = 1+dp[j];
                    cnt[i] = cnt[j];
                } else if(arr[j] < arr[i] and dp[i] == 1+dp[j]) {
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxi) ans += cnt[i];
        }
        
        return ans;
    }
};