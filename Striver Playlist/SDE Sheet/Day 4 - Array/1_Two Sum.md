### [Two Sum](https://leetcode.com/problems/two-sum/)

#### Brute force approach

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> v;
       for(int i=0 ; i<nums.size() ; i++){
           for(int j=i+1 ; j<nums.size() ; j++){
               if(nums[i]+nums[j]==target){
                   v.clear();
                   v.push_back(i);
                   v.push_back(j);
                   break;
               }
           }
       }
        return v;

    }
};
```

#### Optimal using hashmap

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[nums[i]] = i;

        for(int i = 0; i < n; i++){
            int curr = nums[i];
            int req = target - curr;
            if(mp.count(req) and mp[req] != i) return {i, mp[req]};
        }

        return {-1, -1};
    }
};
```
