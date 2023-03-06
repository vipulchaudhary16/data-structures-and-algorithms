# [BFS of graph](https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1)

```cpp
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        
        vector<bool> visited;
        visited.resize(V,false);
        
        list<int> queue;
        visited[0] = true;
        queue.push_back(0);
     
        while(!queue.empty())
        {
            auto s = queue.front();
            ans.push_back(s);
            queue.pop_front();
            for (auto adjecent: adj[s])
            {
                if (!visited[adjecent])
                {
                    visited[adjecent] = true;
                    queue.push_back(adjecent);
                }
            }
        }
        return ans;
    }
};
```