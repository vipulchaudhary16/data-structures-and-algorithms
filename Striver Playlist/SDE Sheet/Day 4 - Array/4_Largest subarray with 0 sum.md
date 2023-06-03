### [Largest subarray with 0 sum](https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1)

```cpp
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int> prefix_firstInd;
        int preSum = 0;
        int ans = 0;
        
        for(int i = 0; i < A.size(); i++){
            int ele = A[i];
            preSum += ele;
            if(preSum == 0) ans = i+1;
            else if(prefix_firstInd.count(preSum)){
                ans = max(ans, i - prefix_firstInd[preSum]);
            } else {
                prefix_firstInd[preSum] = i;
            }
        }
        
        return ans;
        
    }
};
```