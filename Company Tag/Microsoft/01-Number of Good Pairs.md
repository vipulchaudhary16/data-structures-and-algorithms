# [Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs/)

```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        for(int i = nums.size()-1; i>=1; i--){
            for(int j = 0; j < i; j++){
                if(nums[i] == nums[j]) count++;
            }
        }
        return count;
    }
};
```

* TC: O(n^2)

```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        vector<int> freq(101, 0);
        
        for(int num : nums) freq[num]++;
        
        //if a number is repeating n time than we can make total n * (n-1)/2 identical pair using that number so,
        for(int n : freq) ans += n * (n-1)/2;
        
        return ans;
    }
};
```

* TC : O(n)
* SC : O(101)