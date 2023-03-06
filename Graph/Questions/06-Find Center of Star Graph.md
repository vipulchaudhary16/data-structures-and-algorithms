# [Find Center of Star Graph](https://leetcode.com/problems/find-center-of-star-graph/)

```cpp
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int e = edges.size();
        
        unordered_map<int, list<int>> adjList;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            
            if(adjList[u].size() == e) return u;
            if(adjList[v].size() == e) return v;
        }
        
        return -1;
    }
};
```

```cpp
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges[0][0] == edges[1][0] or edges[0][0] == edges[1][1])
            return edges[0][0];
        else return edges[0][1];
    }
};
```