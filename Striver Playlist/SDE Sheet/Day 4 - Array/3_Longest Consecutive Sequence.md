### [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/description/)

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int num : nums) st.insert(num);
        int ans = 0;

        for(int num : nums){
            if(!st.count(num-1)){
                int curr = num;
                int curr_ans = 1;

                while(st.count(curr+1)){
                    curr++;
                    curr_ans++;
                }
                ans = max(ans, curr_ans);
            }
        }

        return ans;
    }
};
```