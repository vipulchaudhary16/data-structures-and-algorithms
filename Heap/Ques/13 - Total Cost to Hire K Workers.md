# [Total Cost to Hire K Workers](https://leetcode.com/problems/total-cost-to-hire-k-workers/description/)

```cpp
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) {
        priority_queue<long long, vector<long long>, greater<long long>> lpq, rpq;//two max heaps
        int n = costs.size() , s = 0, e = n - 1;
        int counter = 0; //to check if we need to push more element to pq after pop or not?
        while(s < cand and counter < n) lpq.push(costs[s++]), counter++;
        while(e >= n - cand and counter < n) rpq.push(costs[e--]), counter++;

        long long ans=0;

        int ses = 0;
        while(ses < k){
            long long a = INT_MAX, b = INT_MAX;
            if(lpq.size() != 0) a = lpq.top();
            if(rpq.size() != 0) b = rpq.top();

            if(a > b){
                ans += b;
                rpq.pop();
                if(s <= e && counter < n) rpq.push(costs[e--]), counter++;
            } else {
                ans += a;
                lpq.pop();
                if(s <= e && counter < n) lpq.push(costs[s++]), counter++;
            }
            ses++;
        }

        return ans;
    }
};
```