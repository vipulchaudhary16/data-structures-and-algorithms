# [Combination Sum](https://leetcode.com/problems/combination-sum/)

```cpp
class Solution {
public:
    void solve(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }
        
        while(ind < arr.size() and arr[ind] <= target){
            ds.push_back(arr[ind]);
            solve(ind, target - arr[ind], arr, ans, ds);
            ++ind;
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, candidates, ans, ds);
        return ans;
    }
};
```