### [Partition a set into two subsets such that the difference of subset sums is minimum.](https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos)


```cpp
#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = 0;
    for(int i : arr) totalSum += i;
    
    int k = totalSum;
    vector<vector<bool>> dp (n, vector<bool>(k+1, false));
    for(int i = 0; i < n; i++) dp[i][0] = true;
    if(arr[0] <= k) dp[0][arr[0]] = true;
    
    for(int i = 1; i < n; i++){
        for(int target = 1; target <= k; target++){
            bool take = target >= arr[i] ? dp[i-1][target - arr[i]] : false;
            bool notTake = dp[i-1][target];
            dp[i][target] = take || notTake;
        }
    }
    
    int mini = 1e8;
    for(int i = 0; i <= k/2; i++){
        if(dp[n-1][i]){
            int s1 = i;
            int s2 = totalSum - i;
            mini = min(mini, abs(s1-s2));
        }
    }
    
    return mini;
}

/*
TC = O(n * totalSum) + O(totalSum/2)
SC = O(n * totalSum)
*/
```

```Optimization```

```cpp
#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = 0;
    for(int i : arr) totalSum += i;
    
    int k = totalSum/2;
    vector<vector<bool>> dp (n, vector<bool>(k+1, false));
    for(int i = 0; i < n; i++) dp[i][0] = true;
    if(arr[0] <= k) dp[0][arr[0]] = true;
    
    for(int i = 1; i < n; i++){
        for(int target = 1; target <= k; target++){
            bool take = target >= arr[i] ? dp[i-1][target - arr[i]] : false;
            bool notTake = dp[i-1][target];
            dp[i][target] = take || notTake;
        }
    }
    
    int mini = 1e8;
    for(int i = 0; i <= k; i++){
        if(dp[n-1][i]){
            int s1 = i;
            int s2 = totalSum - i;
            mini = min(mini, abs(s1-s2));
        }
    }
    
    return mini;
}

/*
TC : O(n * (totalSum)/2) + O(totalSum/2)
SC : O(n * (toalSum)/2)
*/
```