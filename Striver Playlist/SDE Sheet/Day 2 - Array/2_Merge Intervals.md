### [Merge Intervals](https://leetcode.com/problems/merge-intervals/description/)

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;
        sort(v.begin(), v.end());
        vector<int> pointer = v[0];

        for(auto interval : v){
            if(interval[0] <= pointer[1])
                pointer[1] = max(pointer[1], interval[1]);
            else{
                ans.push_back(pointer);
                pointer = interval;
            }
        }
        ans.push_back(pointer);
        return ans;
    }
};
```