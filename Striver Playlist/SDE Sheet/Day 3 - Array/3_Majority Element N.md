### [Majority Element (>N/2 times)](https://leetcode.com/problems/majority-element/)

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans, count = 0;

        for(int element : nums){
            if(count == 0){
                ans = element;
                count = 1;
            }
            else if(element == ans) count++;
            else count--;
        }
        return ans;
    }
};
```