### [Partitions With Given Difference](https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0)

```Recursive DP```

```cpp
#include <bits/stdc++.h> 
int mod = (int) (1e9 + 7);

int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(ind == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = f(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = f(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]=( notTaken + taken) % mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int tot = 0;
    for(int i=0; i<arr.size();i++){
        tot += arr[i];
    }
    
    if((tot - d) < 0 or (tot - d) % 2 == 1) return 0;
    int target = (tot - d)/2;

    vector<vector<int>> dp(n, vector<int> (target+1, -1));
    return f(n-1, target, arr, dp);
}
```

```Tabulation DP```
```cpp
#include <bits/stdc++.h> 
int mod = (int) (1e9 + 7);

int f(int tar, vector<int> &arr){
    int n = arr.size();

    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    if(arr[0] == 0) dp[0][0] =2;  
    else dp[0][0] = 1;  
    
    if(arr[0]!=0 && arr[0]<=tar) dp[0][arr[0]] = 1; 
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= (notTaken + taken)%mod;
        }
    }
    
    return dp[n-1][tar];
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int tot = 0;
    for(int i=0; i<arr.size();i++){
        tot += arr[i];
    }
    
    if((tot - d) < 0 or (tot - d) % 2 == 1) return 0;
    int target = (tot - d)/2;

    return f(target, arr);
}
```

```Space Optimization```

```cpp
#include <bits/stdc++.h> 

int f(int tar, vector<int> &arr){
    int n = arr.size();

    vector<int> prev(tar+1,0), curr(tar+1, 0);
    
    if(arr[0] == 0) prev[0] =2;  
    else prev[0] = 1;  
    
    if(arr[0]!=0 && arr[0]<=tar) prev[arr[0]] = 1; 
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = prev[target];
    
            int taken = 0;
                if(arr[ind]<=target)
                    taken = prev[target-arr[ind]];
        
            curr[target]= (notTaken + taken);
        }
        prev = curr;
    }
    
    return prev[tar];
}

int countPartitions(int n, int d, vector<int> &arr) {
    int tot = 0;
    for(int i=0; i<arr.size();i++){
        tot += arr[i];
    }
    
    if((tot - d) < 0 or (tot - d) % 2 == 1) return 0;
    int target = (tot - d)/2;

    return f(target, arr);
}
```