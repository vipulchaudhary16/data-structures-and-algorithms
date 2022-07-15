# [Minimize the maximum difference between the heights](https://practice.geeksforgeeks.org/problems/minimize-the-heights-i/)

```cpp
class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n);
        
        int ans = arr[n - 1] - arr[0];
        
        int smallest = arr[0];
        int largest = arr[n-1];
        
        
        for(int i = 1; i < n; i++)
        {
            smallest = min(arr[0] + k, arr[i] - k);
            largest = max(arr[n-1]-k, arr[i-1]+k);
            ans = min(ans, largest - smallest);
        }
        
        return ans;
    }
};
```