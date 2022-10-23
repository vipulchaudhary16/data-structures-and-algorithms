# [Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/)

```cpp
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int node, int destination) {
        //preparing adj list
        unordered_map<int, list<int> > adjList;
        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        unordered_map<int, bool> visited;
        
        //BFS and if coming node is = destination then there is path else not
        queue<int> q;
        visited[node] = true;
        q.push(node);
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            cout<<node<<" ";
            if(node == destination) return true;
            
            for (int u: adjList[node])
            {
                if (!visited[u])
                {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        return false;
    }
};
```