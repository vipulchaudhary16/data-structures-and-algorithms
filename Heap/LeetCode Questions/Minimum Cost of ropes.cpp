//Minimum Cost of ropes(https://practice.geeksforgeeks.org/problems minimum-cost-of-ropes-1587115620/1)

class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        for(int i = 0; i < n; i++) pq.push(arr[i]);
        
        long long min_cost = 0;
        while(pq.size() > 1){
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            long long sum = a + b;
            min_cost += sum;
            pq.push(sum);
        }
        
        return min_cost;
    }
};