### [Find the duplicate in an array of N+1 integers.](https://leetcode.com/problems/find-the-duplicate-number/description/)

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] == nums[i]) return nums[i];
        }
        return -1;
    }
};