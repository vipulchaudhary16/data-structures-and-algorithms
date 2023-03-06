### [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)

```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, list<pair<int, int>>> adj(n); //from -> {toi,pricei}
        for(auto flight : flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        vector<int> minCost(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        int stops = 0;
        while(!q.empty() and stops <= k){
            int size = q.size();
            while(size--){
                auto front = q.front();
                q.pop();
                int currCity = front.first;
                int price = front.second;
                
                for(auto connectedCity : adj[currCity]){
                    if(price + connectedCity.second < minCost[connectedCity.first]){
                        minCost[connectedCity.first] = price + connectedCity.second;
                        q.push({connectedCity.first, price + connectedCity.second});
                    }
                }
            }
            stops++;
        }
        
        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
```