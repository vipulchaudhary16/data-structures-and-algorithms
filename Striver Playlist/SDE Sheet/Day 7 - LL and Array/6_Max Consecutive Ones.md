### [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/description/)

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) maxi = max(ans, maxi), ans = 0;
            else ans++;
        }
        maxi = max(ans, maxi);
        return maxi;
    }
};
```
