### [Target Sum](https://www.codingninjas.com/codestudio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos)

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


int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n, target, arr);
}
```