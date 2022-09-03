# [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/submissions/)

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        
        int partIndex = 0;
        for(; partIndex < n; partIndex++){
            if(nums[partIndex] >= 0){
                break;
            }
        }
        
        int i = partIndex - 1 , j = partIndex, k = 0;
        vector<int> res(n);
        
        while(i >= 0 and j < n){
            if(nums[i] * nums[i] < nums[j] * nums[j]){
                res[k++] = nums[i] * nums[i];
                i--;
            } else {
                res[k++] = nums[j] * nums[j];
                j++;
            }
        }
        
        while(i >= 0){
            res[k++] = nums[i] * nums[i];
            i--;
        }
        
        while(j < n){
            res[k++] = nums[j] * nums[j];
            j++;
        }
        
        return res;
    }
};
```