### [Longest Bitonic subsequence](https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1)

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    vector<int> I_dp(n, 1), D_dp(n, 1);
	    
	    int ans = 1;
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < i; j++){
	            if(nums[j] < nums[i]){
	                I_dp[i] = max(I_dp[i], 1 + I_dp[j]);
	            }
	        }
	    }
	    
	    for(int i = n-1; i >= 0; i--){
	        for(int j = i+1; j < n; j++){
	            if(nums[j] < nums[i]){
	                D_dp[i] = max(D_dp[i], 1 + D_dp[j]);
	            }
	        }
	    }
	    
	    for(int i = 0; i < n; i++){
	        ans = max(ans, D_dp[i] + I_dp[i] - 1);
	    }
	    
	    return ans;
	}
};
