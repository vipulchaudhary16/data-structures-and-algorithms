# [Permutations](https://leetcode.com/problems/permutations/)

```cpp
class Solution {
public:
    void solve(vector<int> &ds, vector<vector<int>> &ans, vector<int> nums, vector<bool> &isPeeked){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(!isPeeked[i]){
                ds.push_back(nums[i]);
                isPeeked[i] = true;
                solve(ds, ans, nums, isPeeked);
                isPeeked[i] = false;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        vector<bool> isPeeked(nums.size(), false);
        solve(ds, ans, nums, isPeeked);
        return ans;
        
    }
};
```

```cpp
class Solution {
public:
    void solve(int idx, vector<vector<int>> &ans, vector<int> nums){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i = idx ; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            solve(idx + 1, ans, nums);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, ans, nums);
        return ans;
        
    }
};
```