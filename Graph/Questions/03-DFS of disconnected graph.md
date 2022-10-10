# [DFS of Disconnected Graph](https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar)

```cpp
void dfs(int node, unordered_map<int, list<int>> &adj, vector<int> &visited, 
         vector<int> &component){
    component.push_back(node);
    visited[node]=1;
    
    for(auto adjj : adj[node]){
        if(!visited[adjj]){
            dfs(adjj, adj, visited, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    vector<int> visited(V, 0);
    
    unordered_map<int, list<int>> adj;
    for(auto e : edges){
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i, adj, visited, component);
            ans.push_back(component);
        }
    }
    return ans;
}
```

## Iterative Solution
```cpp
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    vector<int> visited(V, 0);
    
    unordered_map<int, list<int>> adj;
    for(auto e : edges){
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            vector<int> component;
            stack<int> s;
            s.push(i);
            visited[i] = 1;
            while(!s.empty()){
                int top = s.top();
                s.pop();
                component.push_back(top);
                for(auto adj_node : adj[top])
                {
                    if(!visited[adj_node]){
                        visited[adj_node] = 1;
                        s.push(adj_node);
                    }
                }
            }
            ans.push_back(component);
        }
    }
    return ans;
}
```