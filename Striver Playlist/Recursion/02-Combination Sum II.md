# [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)

```cpp
class Solution {
public:
    void solve(int index, int target, vector<int> arr, vector<int> &ds, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        
        for(int i = index; i < arr.size(); i++){
            if(i > index and arr[i] == arr[i-1]) continue; //ignoring duplicates
            if(arr[i] > target) break; //sorted h so aage ja ke koi fayda nahi jha element target se bada ho
            ds.push_back(arr[i]);
            solve(i+1, target - arr[i], arr, ds, ans);
            ds.pop_back(); //back track
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, ds, ans);
        return ans;
    }
};
```