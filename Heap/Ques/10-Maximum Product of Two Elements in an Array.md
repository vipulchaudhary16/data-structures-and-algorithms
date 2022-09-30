# [Maximum Product of Two Elements in an Array](https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/)

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++)
                pq.push((nums[i] - 1) * (nums[j] - 1));
        }
        return pq.top();
    }
};
```
