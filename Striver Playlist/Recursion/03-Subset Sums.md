# [Subset Sums](https://practice.geeksforgeeks.org/problems/subset-sums2234/1)

```cpp
class Solution
{
public:
    void solve(int ind, int sum, vector<int> &ans, vector<int> arr, int n){
        if(ind == n){
            ans.push_back(sum);
            return;
        }
        
        solve(ind + 1, sum + arr[ind], ans, arr, n);
        solve(ind + 1, sum, ans, arr, n);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(0,0,ans,arr,N);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```