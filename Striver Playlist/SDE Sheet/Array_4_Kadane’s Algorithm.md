### [Kadane’s Algorithm](https://leetcode.com/problems/maximum-subarray/description/)

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int curr = 0;
        int s = 0, start = 0, end = 0;

        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];

            if(curr > ans){
                ans = curr;
                start = s;
                end = i;
            }

            if(curr < 0){
                curr = 0;
                s = i + 1;
            }
        }

        cout<<"Start index: "<<start<<" End index: "<<end;
        return ans;
    }
};
```

#### Similar Problems:

* [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/description/)