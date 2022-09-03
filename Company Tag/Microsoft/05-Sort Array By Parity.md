# [Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity/submissions/)

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int h = nums.size() - 1;
        int l = 0;
        
        while(l < h){
            if(nums[l] % 2 != 0 ){
                swap(nums[l], nums[h]);
                h--;
            } else l++;
        }
        
        return nums;
    }
};
```