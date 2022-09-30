# [Merge k Sorted Arrays](https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1)

```cpp
class Solution
{
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<int, vector<int>, greater<int> > min_heap;
        for(auto a : arr){
            for(auto i : a)
                min_heap.push(i);
        }
        
        vector<int> ans;
        int n = min_heap.size();
        for(int i = 0; i < n; i++){
            ans.push_back(min_heap.top());
            min_heap.pop();
        }
        
        return ans;
    }
    
};
```